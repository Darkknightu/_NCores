#pragma once

#include "MetaData.h"

class ColumnDescriptor {
//    ColumnMetaData metaData;

    long offset;
    string metaData;
    int blockCount;
    vector<BlockDescriptor> blocks;

public:
    ColumnDescriptor(){}

    ColumnDescriptor(const ColumnDescriptor &columnreader){
        offset=columnreader.offset;
        metaData=columnreader.metaData;
        blockCount=columnreader.blockCount;
        blocks=columnreader.blocks;
    }
    ColumnDescriptor(int count, long _offset):blockCount(count),offset(_offset){
        //metaData=meta;
    }

    long getOffset(){
        return offset;
    }

    void setBlocks(vector<BlockDescriptor> _blocks){
        this->blocks.assign(_blocks.begin(),_blocks.begin()+_blocks.size());
    }

    vector<BlockReader> getBlocks(){
        return blocks;
    }

    BlockReader getBlock(int b){
        return blocks[b];
    }

    int getblockCount(){
        return blockCount;
    }

    void pushBlock(BlockReader block){
        blocks.push_back(block);
    }

public:
//    ColumnDescriptor(ColumnMetaData columnMetaData) : metaData(columnMetaData) {
//    }
};
