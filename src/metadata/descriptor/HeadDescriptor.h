//
// Created by Vince Tu on 2019/8/28.
//

#ifndef CORES_HEADDESCRIPTOR_H
#define CORES_HEADDESCRIPTOR_H

class HeadDescriptor{
    int rowCount;
    int blockSize;
    int columnCount;
    string metaData;
    vector<ColumnReader> columns;

public:
    HeadDescriptor(){}

    int getRowCount(){
        return rowCount;
    }

    int getColumnCount(){
        return columnCount;
    }

    vector<ColumnDescriptor> getColumns(){
        return columns;
    }

    ColumnDescriptor getColumn(int c){
        return columns[c];
    }

    string getMetaData(){
        return metaData;
    }

    void setColumns(vector<ColumnDescriptor> _columns){
        this->columns.assign(_columns.begin(),_columns.begin()+_columns.size());
    }

    void readHeader(istream& is){
        is.read((char*)&this->blockSize, sizeof(this->blockSize));
        is.read((char*)&this->rowCount, sizeof(this->rowCount));
        is.read((char*)&this->columnCount, sizeof(this->columnCount));
        getline(is,metaData);

        unique_ptr<vector<ColumnDescriptor>> columns( new vector<ColumnDescriptor>());
        for (int i = 0; i <columnCount ; ++i) {
            int blockCount;
            is.read((char*)&blockCount, sizeof(blockCount));
            long offset;
            is.read((char*)&offset, sizeof(offset));
            unique_ptr<vector<BlockDescriptor>> blocks(new vector<BlockDescriptor>());
            for (int j = 0; j < blockCount; ++j) {
                unique_ptr<BlockDescriptor> block(new BlockReader);
                block->read(is);
                blocks->push_back(*block);
            }
            int tmp=blocks->size();
            unique_ptr<ColumnDescriptor>column (new ColumnDescriptor(blockCount,offset));
            column->setBlocks(*blocks);
            columns->push_back(*column);
        }
        this->setColumns(*columns);
    }
};

#endif //CORES_HEADDESCRIPTOR_H
