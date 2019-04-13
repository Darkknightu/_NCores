//
// Created by Michael on 2018/12/2.
//
#include "BlockCache.h"
#include "utils.h"
#include "Bitset.h"
#include <vector>
#include <memory>

using namespace std;

#define ROW_COUNT 16*1024

#define BLOCK_COUNT 4096

#define BLOCK_LIMIT 4096

#define ROWCOUNT 1024

#define FILTERING true

#define FILTERINGRATE 0.5

namespace test_write {
    template<class T>
    void writedata(FILE* fp,T value, int blocksize, int rowcount,int offset) {
        PrimitiveBlock<T> *intBlock = new PrimitiveBlock<T>(fp, offset, 0, blocksize);
        unsigned long long total = 0;
        Tracer tracer;
        tracer.startTime();
        int rowcountperblock=blocksize / sizeof(T);
        for (int k = 0; k < rowcount / rowcountperblock; k++) {
            for (int i = 0; i < rowcountperblock; i++) {
                intBlock->set(i, k * rowcountperblock + i);
            }
            intBlock->appendToFile();
        }
        cout << "Ingestion: " << tracer.getRunTime() << endl;
        delete intBlock;
    }

    template<>
    void writedata(FILE* fp,string value, int blocksize, int rowcount,int offset) {
        PrimitiveBlock<char*> *intBlock = new PrimitiveBlock<char*>(fp, offset, 0, blocksize);
        unsigned long long total = 0;
        Tracer tracer;
        tracer.startTime();
        for (int k = 0; k < rowcount / (blocksize / 16); k++) {
            for (int i = 0; i < blocksize; i+=16) {
                intBlock->set(i, "my test string");
            }
            intBlock->appendToFile();
        }
        cout << "Ingestion: " << tracer.getRunTime() << endl;

        delete intBlock;
    }

    template<class T>
    void readfile(char* fname,T value, int blocksize, int rowcount) {
        FILE *fp = fopen(fname, "rb+");
        unsigned long long verify = 0;
        PrimitiveBlock<T> *intBlock = new PrimitiveBlock<T>(fp, 0, 0, blocksize);
        unsigned long long total = 0;
        Tracer tracer;
        tracer.startTime();
        unsigned long long count = 0;
        unsigned long long filter = rowcount * sizeof(long) * FILTERINGRATE;
        int rowpercount=blocksize / sizeof(T);
        for (int k = 0; k < rowcount / rowpercount; k++) {
            intBlock->loadFromFile();
            for (int i = 0; i < rowpercount; i++) {
                if (FILTERING) {
                    if (intBlock->get(i) > filter) {
                        count++;
                    }
                } else {
                    verify += intBlock->get(i);
                }
            }
        }
        cout << "Load: " << tracer.getRunTime() << "\t" << total << "<->" << count << "<->" << verify << endl;
        fclose(fp);
        delete intBlock;
    }
}

class BlockReader{
    int rowCount;
    int lengthOffset;
    int size;

public:
    BlockReader():lengthOffset(0){}

    BlockReader(istream is){
        is.read((char*)&rowCount, sizeof(rowCount));
        is.read((char*)&size, sizeof(size));
    }

    void writeTo(ostream os){
        os.write((char *)&rowCount, sizeof(rowCount));
        os.write((char *)size, sizeof(size));
    }

    int getRowcount(){
        return rowCount;
    }

    void read(istream& is){
        is.read((char*)&this->rowCount, sizeof(this->rowCount));
        is.read((char*)&this->size, sizeof(this->size));
    }
};

class ColumnReader{
    string metaData;
    int blockCount;
    vector<BlockReader> blocks;

public:
    ColumnReader(){}

    ColumnReader(const ColumnReader &columnreader){
        metaData=columnreader.metaData;
        blockCount=columnreader.blockCount;
        blocks=columnreader.blocks;
    }
    ColumnReader(int count):blockCount(count){
        //metaData=meta;
    }

    void setBlocks(vector<BlockReader> _blocks){
        this->blocks.assign(_blocks.begin(),_blocks.begin()+_blocks.size());
    }

    vector<BlockReader> getBlocks(){
        return blocks;
    }

    int getblockCount(){
        return blockCount;
    }

    void pushBlock(BlockReader block){
        blocks.push_back(block);
    }
};

class HeadReader{
    long offset;
    int rowCount;
    int blockSize;
    int columnCount;
    string metaData;
    vector<ColumnReader> columns;

public:
    HeadReader(){}

    int getOffset(){
        return offset;
    }

    int getRowCount(){
        return rowCount;
    }

    int getColumnCount(){
        return columnCount;
    }

    vector<ColumnReader> getColumns(){
        return columns;
    }

    string getMetaData(){
        return metaData;
    }

    void setColumns(vector<ColumnReader> _columns){
        this->columns.assign(_columns.begin(),_columns.begin()+_columns.size());
    }

    void readHeader(istream& is){
        is.read((char*)&this->offset, sizeof(this->offset));
        is.read((char*)&this->blockSize, sizeof(this->blockSize));
        is.read((char*)&this->rowCount, sizeof(this->rowCount));
        is.read((char*)&this->columnCount, sizeof(this->columnCount));
        getline(is,metaData);
        unique_ptr<vector<ColumnReader>> columns( new vector<ColumnReader>());
        for (int i = 0; i <columnCount ; ++i) {
            int blockCount;
            is.read((char*)&blockCount, sizeof(blockCount));
            unique_ptr<vector<BlockReader>> blocks(new vector<BlockReader>());
            for (int j = 0; j < blockCount; ++j) {
                unique_ptr<BlockReader> block(new BlockReader);
                block->read(is);
                blocks->push_back(*block);
            }
            int tmp=blocks->size();
            unique_ptr<ColumnReader>column (new ColumnReader(blockCount));
            column->setBlocks(*blocks);
            columns->push_back(*column);
        }
        this->setColumns(*columns);
    }
};

class RecordReader{

};

template<class T>
void writetocolumnreader(fstream &fp, int _rowcount, int blocksize, T type) {
    int blockcount = _rowcount / (blocksize / sizeof(T));
    fp.write((char *) &blockcount, sizeof(blockcount));
    int rowcount = blocksize / sizeof(T);
    int size = blocksize;
    for (int i = 0; i < blockcount; ++i) {
        fp.write((char *) &rowcount, sizeof(rowcount));
        fp.write((char *) &size, sizeof(size));
    }
}

template<>
void writetocolumnreader(fstream &fp, int _rowcount, int blocksize, string type) {
    int blockcount = _rowcount / (blocksize / 16);
    fp.write((char *) &blockcount, sizeof(blockcount));
    int rowcount = blocksize / 16;
    int size = blocksize;
    for (int i = 0; i < blockcount; ++i) {
        fp.write((char *) &rowcount, sizeof(rowcount));
        fp.write((char *) &size, sizeof(size));
    }
}

void writetofile(char *fname, int rowcount, int blocksize) {
    FILE *tmp=fopen(fname,"wb+");
    fclose(tmp);
    fstream fs;
    fs.open(fname, ios_base::out | ios_base::binary);
    int collumncount = 3;
    string metaData = "{\"type\":\"record\",\"name\":\"test\",\"fields\":[{\"name\":\"test_int\",\"type:\"int\"},{\"name\":\"test_int\",\"type:\"int\"},{\"name\":\"test_int\",\"type:\"int\"}]";
    long offset=0;
    fs.write((char *) &offset, sizeof(offset));
    fs.write((char *) &blocksize, sizeof(blocksize));
    fs.write((char *) &rowcount, sizeof(rowcount));
    fs.write((char *) &collumncount, sizeof(collumncount));
    fs << metaData << endl;
    int typeint;
    long long typelong;
    string typestring;
    writetocolumnreader(fs, rowcount, blocksize, typeint);
    writetocolumnreader(fs, rowcount, blocksize, typelong);
    writetocolumnreader(fs, rowcount, blocksize, typestring);
    offset=fs.tellg();
    fs.seekg(0);
    fs.write((char *) &offset, sizeof(offset));
    fs.close();
    FILE* fp=fopen(fname,"ab+");
    test_write::writedata(fp,typeint,blocksize,rowcount,0);
    test_write::writedata(fp,typelong,blocksize,rowcount,0);
    test_write::writedata(fp,typestring,blocksize,rowcount,0);
    fflush(fp);
    fclose(fp);
}

void readfromfile(char *fname){
    ifstream file_in;
    file_in.open(fname, ios_base::in|ios_base::binary);
    unique_ptr<HeadReader> headreader(new HeadReader());
    headreader->readHeader(file_in);
    file_in.close();
    FILE* fp=fopen(fname,"rb+");
    int rowcount=headreader->getRowCount();
    unique_ptr<Bitset> intset(new Bitset(rowcount));
    unique_ptr<PrimitiveBlock<int>>intBlock(new PrimitiveBlock<int>(fp, 0L, 0, BLOCK_LIMIT));
    fseek(fp,headreader->getOffset(), SEEK_SET);
    int tmp=0;
    for (int i = 0; i < headreader->getColumns()[0].getblockCount(); ++i) {
        intBlock->loadFromFile();
        for (int j = 0; j < headreader->getColumns()[0].getBlocks()[0].getRowcount(); ++j) {
            tmp++;
            if(intBlock->get(j)%1000==0){
                intset->set(tmp);
            };
        }
    }
    unique_ptr<PrimitiveBlock<long>>longBlock(new PrimitiveBlock<long>(fp, 0L, 0, BLOCK_LIMIT));
    for (int i = 0; i < headreader->getColumns()[1].getBlocks().size(); ++i) {
        longBlock->loadFromFile();
        for (int j = 0; j < headreader->getColumns()[1].getBlocks()[0].getRowcount(); ++j) {
            longBlock->get(j);
        }
    }
    unique_ptr<PrimitiveBlock<char*>>stringBlock(new PrimitiveBlock<char*>(fp, 0L, 0, BLOCK_LIMIT));
    for (int i = 0; i < headreader->getColumns()[2].getBlocks().size(); ++i) {
        stringBlock->loadFromFile();
        for (int j = 0; j < headreader->getColumns()[2].getBlocks()[0].getRowcount(); ++j) {
            stringBlock->get(j);
        }
    }
    fclose(fp);
}

int main(int argc, char **argv) {
    if(strcmp(argv[1], "tw") == 0){
        writetofile("./text.dat",ROW_COUNT,BLOCK_LIMIT);
    }
    else if(strcmp(argv[1], "tr") == 0){
        readfromfile("./text.dat");
    }
    if (strcmp(argv[1], "st") == 0) {
        FILE *fp = fopen("./text.dat", "wb+");
        ifstream in(argv[2]);
        char *_cache = (char *) calloc(BLOCK_LIMIT, sizeof(char));
        PrimitiveBlock<char> *intBlock = new PrimitiveBlock<char>(fp, _cache, BLOCK_LIMIT);
        short *l = (short *) _cache;
        string line;
        short length = 2;
        int amount = 0;
        int i = 0;
        char *tmp = new char[(int) BLOCK_LIMIT];
        if (in) // 有该文件
        {
            while (getline(in, line)) // line中不包括每行的换行符
            {
                if ((length + 1) > BLOCK_LIMIT) {
                    char *str = (char *) (l + i + 1);
                    std::strncpy((char *) str, tmp, amount + 1);
                    l[0] = i;
                    intBlock->appendToFile();
                    memset(tmp, 0, BLOCK_LIMIT);
                    std::strcpy(tmp, (char *) line.c_str());
                    l[1] = line.length();
                    amount = line.length();
                    i = 1;
                    length = 2;
                } else {
                    strcat(tmp, (char *) line.c_str());
                    l[i + 1] = line.length();
                    amount += line.length();
                    length += l[i + 1] + 2;
                    i++;
                }
            }

        } else // 没有该文件
        {
            cout << "no such file" << endl;
        }
        fflush(fp);
        fclose(fp);
        delete intBlock;
    } else if (strcmp(argv[1], "w") == 0) {
        if (strcmp(argv[2], "l") == 0) {
            long type;
            FILE *fp = fopen("./text.dat", "wb+");
            test_write::writedata(fp,type, BLOCK_LIMIT, BLOCK_COUNT * BLOCK_LIMIT / sizeof(long),0);
        } else if (strcmp(argv[2], "i") == 0) {
            int type;
            FILE *fp = fopen("./text.dat", "wb+");
            test_write::writedata(fp, type,BLOCK_LIMIT, BLOCK_COUNT * BLOCK_LIMIT / sizeof(int),0);
        } else if (strcmp(argv[2], "s") == 0) {
            FILE *fp = fopen("./text.dat", "wb+");
            ifstream in(argv[3]);
            string line;
            unsigned long long total = 0;
            Tracer tracer;
            tracer.startTime();
            PrimitiveBlock<char *> *intBlock = new PrimitiveBlock<char *>(fp, 0L, 1024 * 1024, BLOCK_LIMIT);
            long a_length = 0;
            while (getline(in, line)) {
                if ((a_length + line.length() + 3) >= BLOCK_LIMIT) {
                    intBlock->appendToFile();
                    intBlock->set(0, (char *) line.c_str());
                    a_length = line.length() + 3;
                } else {
                    intBlock->set(a_length, (char *) line.c_str());
                    a_length += line.length() + 3;
                }
            }
            intBlock->appendToFile();
            cout << "Ingestion: " << tracer.getRunTime() << endl;
            fflush(fp);
            fclose(fp);
            delete intBlock;
        }
    } else if (strcmp(argv[1], "r") == 0) {
        char* fname="./test.dat";
        if (strcmp(argv[2], "l") == 0) {
            long type;
            test_write::readfile(fname,type, BLOCK_LIMIT, BLOCK_COUNT * BLOCK_LIMIT / sizeof(long));
        } else if (strcmp(argv[2], "i") == 0) {
            int type;
            test_write::readfile(fname,type, BLOCK_LIMIT, BLOCK_COUNT * BLOCK_LIMIT / sizeof(int));
        } else if (strcmp(argv[2], "s") == 0) {
            FILE *fp = fopen("./text.dat", "rb+");
            ifstream in(argv[3]);
            char *line;
            PrimitiveBlock<char *> *intBlock = new PrimitiveBlock<char *>(fp, 0L, 1024 * 1024, BLOCK_LIMIT);
            long a_length = 0;
            short length = 1;
            intBlock->loadFromFile();
            char *verify = 0;
            Tracer tracer;
            tracer.startTime();
            unsigned long long count = 0;
            while (!feof(fp)) {
                if (length == 0) {
                    intBlock->loadFromFile();
                    line = intBlock->get(0);
                    length = strlen(line);
                    a_length = length + 3;
                } else {
                    line = intBlock->get(a_length);
                    length = strlen(line);
                    a_length += length + 3;
                }
            }
            intBlock->appendToFile();
            for (int k = 0; k < BLOCK_COUNT; k++) {
                intBlock->loadFromFile();
                for (int i = 0; i < BLOCK_LIMIT / 16; i++) {
                    if (FILTERING) {
//                        if (intBlock->get(i) > filter) {
//                            count++;
//                        }
                    } else {
                        verify = intBlock->get(16 * i);
                        cout << verify << endl;
                    }
                }
            }
            cout << "Load: " << tracer.getRunTime() << "\t" << "<->" << count << "<->" << verify << endl;
            fclose(fp);
            delete intBlock;
        }
    }
    return 0;
}
