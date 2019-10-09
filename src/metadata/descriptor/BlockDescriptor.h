//
// Created by Vince Tu on 2019/8/28.
//

#ifndef CORES_BLOCKDESCRIPTOR_H
#define CORES_BLOCKDESCRIPTOR_H

class BlockDescriptor{
    int lastRow;
//    int lengthOffset;
    int size;

public:
    BlockDescriptor():lengthOffset(0){}

    BlockDescriptor(istream is){
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

#endif //CORES_BLOCKDESCRIPTOR_H
