//
// Created by Michael on 2018/12/2.
//
#include "BlockCache.h"
#include "utils.h"
#include "Bitset.h"
#include <vector>
#include <memory>

using namespace std;

#define ROW_COUNT 256

#define BLOCK_COUNT 4096

#define BLOCK_LIMIT 1024

#define ROWCOUNT 1024

#define FILTERING true

#define FILTERINGRATE 10000

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
    long offset;
    string metaData;
    int blockCount;
    vector<BlockReader> blocks;

public:
    ColumnReader(){}

    ColumnReader(const ColumnReader &columnreader){
        offset=columnreader.offset;
        metaData=columnreader.metaData;
        blockCount=columnreader.blockCount;
        blocks=columnreader.blocks;
    }
    ColumnReader(int count, long _offset):blockCount(count),offset(_offset){
        //metaData=meta;
    }

    long getOffset(){
        return offset;
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
    int rowCount;
    int blockSize;
    int columnCount;
    string metaData;
    vector<ColumnReader> columns;

public:
    HeadReader(){}

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
        is.read((char*)&this->blockSize, sizeof(this->blockSize));
        is.read((char*)&this->rowCount, sizeof(this->rowCount));
        is.read((char*)&this->columnCount, sizeof(this->columnCount));
        getline(is,metaData);
        unique_ptr<vector<ColumnReader>> columns( new vector<ColumnReader>());
        for (int i = 0; i <columnCount ; ++i) {
            int blockCount;
            is.read((char*)&blockCount, sizeof(blockCount));
            long offset;
            is.read((char*)&offset, sizeof(offset));
            unique_ptr<vector<BlockReader>> blocks(new vector<BlockReader>());
            for (int j = 0; j < blockCount; ++j) {
                unique_ptr<BlockReader> block(new BlockReader);
                block->read(is);
                blocks->push_back(*block);
            }
            int tmp=blocks->size();
            unique_ptr<ColumnReader>column (new ColumnReader(blockCount,offset));
            column->setBlocks(*blocks);
            columns->push_back(*column);
        }
        this->setColumns(*columns);
    }
};

class RecordReader{

};

template<class T>
long writetocolumnreader(fstream &fp, int _rowcount, int blocksize, T type) {
    cout<<blocksize<<" "<<_rowcount<<" "<< sizeof(T)<<endl;
    int blockcount = _rowcount / (blocksize / sizeof(T));
    fp.write((char *) &blockcount, sizeof(blockcount));
    long tmp_fooset=fp.tellg();
    long offset=0;
    fp.write((char *) &offset, sizeof(offset));
    int rowcount = blocksize / sizeof(T);
    int size = blocksize;
    for (int i = 0; i < blockcount; ++i) {
        fp.write((char *) &rowcount, sizeof(rowcount));
        fp.write((char *) &size, sizeof(size));
    }
    return tmp_fooset;
}

template<>
long writetocolumnreader(fstream &fp, int _rowcount, int blocksize, string type) {
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
//    FILE *tmp=fopen(fname,"wb+");
//    fclose(tmp);
//    fstream fs;
//    fs.open(fname, ios_base::out | ios_base::binary);
//    int collumncount = 3;
//    string metaData = "{\"type\":\"record\",\"name\":\"test\",\"fields\":[{\"name\":\"test_int\",\"type:\"int\"},{\"name\":\"test_int\",\"type:\"int\"},{\"name\":\"test_int\",\"type:\"int\"}]";
//    long offset=0;
//    fs.write((char *) &offset, sizeof(offset));
//    fs.write((char *) &blocksize, sizeof(blocksize));
//    fs.write((char *) &rowcount, sizeof(rowcount));
//    fs.write((char *) &collumncount, sizeof(collumncount));
//    fs << metaData << endl;
//    int typeint;
//    long long typelong;
//    string typestring;
//    writetocolumnreader(fs, rowcount, blocksize, typeint);
//    writetocolumnreader(fs, rowcount, blocksize, typelong);
//    writetocolumnreader(fs, rowcount, blocksize, typestring);
//    offset=fs.tellg();
//    fs.seekg(0);
//    fs.write((char *) &offset, sizeof(offset));
//    fs.close();
//    FILE* fp=fopen(fname,"ab+");
//    test_write::writedata(fp,typeint,blocksize,rowcount,0);
//    test_write::writedata(fp,typelong,blocksize,rowcount,0);
//    test_write::writedata(fp,typestring,blocksize,rowcount,0);
//    fflush(fp);
//    fclose(fp);
    FILE *tmp=fopen(fname,"wb+");
    fclose(tmp);
    fstream fs;
    fs.open(fname, ios_base::out | ios_base::binary);
    int collumncount = 2;
    string metaData = "{\"type\":\"record\",\"name\":\"test\",\"fields\":[{\"name\":\"test_int\",\"type:\"int\"},{\"name\":\"test_float\",\"type:\"float\"}]";
    long offset_i=0;
    long offset_f=0;
    fs.write((char *) &blocksize, sizeof(blocksize));
    fs.write((char *) &rowcount, sizeof(rowcount));
    fs.write((char *) &collumncount, sizeof(collumncount));
    fs << metaData << endl;
    int typeint;
    float typefloat;
    offset_i=writetocolumnreader(fs, rowcount, blocksize, typeint);
    offset_f=writetocolumnreader(fs, rowcount, blocksize, typefloat);
    long result_i=fs.tellg();
    fs.close();
    FILE* fp=fopen(fname,"ab+");
    test_write::writedata(fp,typeint,blocksize,rowcount,0);
    long result_f=ftell(fp);
    test_write::writedata(fp,typefloat,blocksize,rowcount,0);
    fflush(fp);
    fclose(fp);
    fp=fopen(fname,"rb+");
    fseek(fp,offset_i,SEEK_SET);
    fwrite((char *) &result_i, sizeof(result_i),1,fp);
    fseek(fp,offset_f,SEEK_SET);
    fwrite((char *) &result_f, sizeof(result_f),1,fp);
    fs.close();
}

void readfromfile(char *fname){
    ifstream file_in;
    file_in.open(fname, ios_base::in|ios_base::binary);
    unique_ptr<HeadReader> headreader(new HeadReader());
    headreader->readHeader(file_in);
    file_in.close();
    FILE* fp=fopen(fname,"rb");
    int rowcount=headreader->getRowCount();
    Bitset* intset=new Bitset(rowcount);
    fseek(fp,headreader->getColumns()[0].getOffset(), SEEK_SET);
    PrimitiveBlock<int>* intBlock=new PrimitiveBlock<int>(fp, 0L, 0, BLOCK_LIMIT);
    int b_count=headreader->getColumns()[0].getblockCount();
    int r_count=headreader->getColumns()[0].getBlocks()[0].getRowcount();
    int tmp;
    cout<<"read int..."<<endl;
    for (int i = 0; i < b_count; ++i) {
        intBlock->loadFromFile();
        for (int j = 0; j < r_count; ++j) {
            if(FILTERING){
                if((tmp=intBlock->get(j))%FILTERINGRATE==0){
                    intset->set(i*b_count+j);}
            } else{
                intBlock->get(j);
            };
        }
    }
    fseek(fp,headreader->getColumns()[1].getOffset(), SEEK_SET);
    PrimitiveBlock<float>* floatBlock=new PrimitiveBlock<float>(fp, 0L, 0, BLOCK_LIMIT);
    b_count=headreader->getColumns()[1].getblockCount();
    r_count=headreader->getColumns()[1].getBlocks()[0].getRowcount();
    cout<<"read float..."<<endl;
    float tmp_f;
    for (int i = 0; i < b_count; ++i) {
        floatBlock->loadFromFile();
        for (int j = 0; j < r_count; ++j) {
            if(FILTERING){
                if((intBlock->get(j))%FILTERINGRATE==0){
                    intset->set(i*b_count+j);}
            } else{
                intBlock->get(j);
            };
        }
    }
    fclose(fp);
    delete(intset);
    delete(intBlock);
    delete(floatBlock);
}

void formrecord (char* fname){
    ifstream file_in;
    file_in.open(fname, ios_base::in|ios_base::binary);
    unique_ptr<HeadReader> headreader(new HeadReader());
    headreader->readHeader(file_in);
    file_in.close();
    int b_count=headreader->getColumns()[1].getblockCount();
    int r_count=headreader->getColumns()[1].getBlocks()[0].getRowcount();
    FILE* fp_i=fopen(fname,"rb");
    fseek(fp_i,headreader->getColumns()[0].getOffset(), SEEK_SET);
    FILE* fp_f=fopen(fname,"rb");
    fseek(fp_f,headreader->getColumns()[1].getOffset(), SEEK_SET);
    PrimitiveBlock<int>* int_Block=new PrimitiveBlock<int>(fp_i, 0L, 0, BLOCK_LIMIT);
    PrimitiveBlock<float>* float_Block=new PrimitiveBlock<float>(fp_f, 0L, 0, BLOCK_LIMIT);
    cout<<"form record..."<<endl;
    char* record=new char[8];
    for (int i = 0; i < b_count; ++i) {
        int_Block->loadFromFile();
        float_Block->loadFromFile();
        for (int j = 0; j < r_count; ++j) {
            *(int*)record=int_Block->get(j);
            *(float*)(record+4)=float_Block->get(j);
        };
    }
    fclose(fp_f);
    fclose(fp_i);
    delete (record);
    delete(int_Block);
    delete(float_Block);
}

int main(int argc, char **argv) {
    if(strcmp(argv[1], "tw") == 0){
        writetofile("./text.dat",ROW_COUNT,BLOCK_LIMIT);
    }
    else if(strcmp(argv[1], "tr") == 0){
        readfromfile("./text.dat");
    }
    else if(strcmp(argv[1], "rf") == 0){
        formrecord("./text.dat");
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
