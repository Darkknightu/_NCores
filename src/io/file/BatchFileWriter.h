//
// Created by Vince Tu on 2019/9/1.
//

#ifndef CORES_BATCHFILEWRITER_H
#define CORES_BATCHFILEWRITER_H

#include <memory.h>
#include "Generic.h"
#include "vector"
#include "string"
#include "iostream"

using namespace std;



class BatchFileWriter{
    BatchFileWriter(){

    }

public:

    BatchFileWriter(GenericDatum record,string path,int blocksize){
        this->record=new GenericRecord(record.value<GenericRecord>());
        this->path=path;
        this->blocksize=blocksize;
        column_num=this->record->fieldCount();
        head_files=(FILE**)(malloc(column_num* sizeof(FILE*)));
        data_files=(FILE**)(malloc(column_num* sizeof(FILE*)));
        data_buffers=(char**)(malloc(column_num*sizeof(char*)));
        heads_info=(int**)(malloc(column_num*sizeof(int*)));
        head_index= new int[column_num]();
        data_index= new int[column_num]();
        file_offset = new int[column_num]();
        block_num = new int[column_num]();
        strl=new int[column_num]();

        for (int i = 0; i <column_num ; ++i) {
            head_files[i]=fopen((path+"/file"+to_string(i)+".head").data(),"wb+");
            data_files[i]=fopen((path+"/file"+to_string(i)+".data").data(),"wb+");
            data_buffers[i]=new char[blocksize];
            heads_info[i]=new int[blocksize];
        }

    }

private:
    string path;
    int blocksize;
    GenericRecord* record;
    int column_num;
    FILE** data_files;
    FILE** head_files;
    char** data_buffers;
    int** heads_info;
    int* data_index;
    int* head_index;
    int* file_offset;
    int* block_num;
    int* strl;

    FILE* outfile;

    void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
    {
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(std::string::npos != pos2)
        {
            v.push_back(s.substr(pos1, pos2-pos1));
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length())
            v.push_back(s.substr(pos1));
    }

public:

    long getInd(int ind){
        return record->fieldAt(ind).value<long>();
    }

    void setArr(int ind,vector <GenericDatum> arr){
        record->fieldAt(ind).value<GenericArray>().value()=arr;
    }

    GenericRecord getRecord() {
        return *record;
    }

//    GenericDatum getRecord(){
//        return GenericDatum(*record);
//    }

    void readLine(string line){
        vector<string> v;
        SplitString(line,v,"|");
        for(vector<string>::size_type i = 0; i != v.size(); ++i){
            switch (record->fieldAt(i).type()){
                case AVRO_INT:{
                    int tmp=stoi(v[i]);
                    record->fieldAt(i)=tmp;
                    break;}
                case AVRO_FLOAT:{
                    float tmp=stof(v[i]);
                    record->fieldAt(i)=tmp;
                    break;}
                case AVRO_LONG:{
                    long tmp=stol(v[i]);
                    record->fieldAt(i)=tmp;
                    break;}
                case AVRO_DOUBLE:{
                    double tmp=stod(v[i]);
                    record->fieldAt(i)=tmp;
                    break;}
                case AVRO_BYTES:{
                    char tmp=((char*)v[i].c_str())[0];
                    record->fieldAt(i)=tmp;
                    break;}

                case AVRO_STRING:{
                    record->fieldAt(i)=v[i];
                    break;}
            }
        }

    }

    void writeRecord(){
        for (int i = 0; i < column_num; ++i) {
            switch (record->fieldAt(i).type()){
                case AVRO_INT:{
                    int tmp=record->fieldAt(i).value<int>();
                    *(int*)(&data_buffers[i][data_index[i]])=tmp;
                    data_index[i]+= sizeof(int);
                    if(data_index[i]>=blocksize){
                        data_index[i]=0;
                        fwrite(data_buffers[i], sizeof(char),blocksize,data_files[i]);
                        block_num[i]++;
                        memset( data_buffers[i] , 0 , blocksize*sizeof(char) );
                        heads_info[i][head_index[i]++]=blocksize/ sizeof(int);
                        file_offset[i]+=blocksize/ sizeof(int);
                        heads_info[i][head_index[i]++]=file_offset[i];
                        if(head_index[i]>=blocksize){
                            fwrite(heads_info[i], sizeof(int),blocksize,head_files[i]);
                            memset( heads_info[i] , 0 , blocksize*sizeof(int) );
                            head_index[i]=0;
                        }
                    }
                    break;}
                case AVRO_LONG:{
                    long tmp=record->fieldAt(i).value<long>();
                    *(long*)(&(data_buffers[i][data_index[i]]))=tmp;
                    data_index[i]+= sizeof(long);
                    int n=0;
                    if(data_index[i]>=blocksize){
                        if(i==0){
//                        if(n==0){
//                            long* tmp_l=(long*)(data_buffers[0]);
//                            for (int i = 0; i <blocksize/ sizeof(long) ; ++i) {
//                                cout<<*tmp_l<<" ";
//                                tmp_l++;
//                            }
//                        }
                        }
                        data_index[i]=0;
                        fwrite(data_buffers[i], sizeof(char),blocksize,data_files[i]);
                        block_num[i]++;
                        memset( data_buffers[i] , 0 , blocksize*sizeof(char) );
                        heads_info[i][head_index[i]++]=blocksize/ sizeof(long);
                        file_offset[i]+=blocksize/ sizeof(long);
                        heads_info[i][head_index[i]++]=file_offset[i];
                        if(head_index[i]>=blocksize){
                            fwrite(heads_info[i], sizeof(int),blocksize,head_files[i]);
                            memset( heads_info[i] , 0 , blocksize*sizeof(int) );
                            head_index[i]=0;
                        }
                    }
                    break;}
                case AVRO_DOUBLE:{
                    double tmp=record->fieldAt(i).value<double>();
                    *(double*)(&data_buffers[i][data_index[i]])=tmp;
                    data_index[i]+= sizeof(double);
                    if(data_index[i]>=blocksize){
                        data_index[i]=0;
                        fwrite(data_buffers[i], sizeof(char),blocksize,data_files[i]);
                        block_num[i]++;
                        memset( data_buffers[i] , 0 , blocksize*sizeof(char) );
                        heads_info[i][head_index[i]++]=blocksize/ sizeof(double);
                        file_offset[i]+=blocksize/ sizeof(double);
                        heads_info[i][head_index[i]++]=file_offset[i];
                        if(head_index[i]>=blocksize){
                            fwrite(heads_info[i], sizeof(int),blocksize,head_files[i]);
                            memset( heads_info[i] , 0 , blocksize*sizeof(int) );
                            head_index[i]=0;
                        }
                    }
                    break;}
                case AVRO_FLOAT:{
                    float tmp=record->fieldAt(i).value<float>();
                    *(float*)(&data_buffers[i][data_index[i]])=tmp;
                    data_index[i]+= sizeof(float);
                    if(data_index[i]>=blocksize){
                        data_index[i]=0;
                        fwrite(data_buffers[i], sizeof(char),blocksize,data_files[i]);
                        block_num[i]++;
                        memset( data_buffers[i] , 0 , blocksize*sizeof(char) );
                        heads_info[i][head_index[i]++]=blocksize/ sizeof(float);
                        file_offset[i]+=blocksize/ sizeof(float);
                        heads_info[i][head_index[i]++]=file_offset[i];
                        if(head_index[i]>=blocksize){
                            fwrite(heads_info[i], sizeof(int),blocksize,head_files[i]);
                            memset( heads_info[i] , 0 , blocksize*sizeof(int) );
                            head_index[i]=0;
                        }
                    }
                    break;}
                case AVRO_BYTES:{
                    char tmp=record->fieldAt(i).value<char>();
                    *(char*)(&data_buffers[i][data_index[i]])=tmp;
                    data_index[i]+= sizeof(char);
                    if(data_index[i]>=blocksize){
                        data_index[i]=0;
                        fwrite(data_buffers[i], sizeof(char),blocksize,data_files[i]);
                        block_num[i]++;
                        memset( data_buffers[i] , 0 , blocksize*sizeof(char) );
                        heads_info[i][head_index[i]++]=blocksize/ sizeof(char);
                        file_offset[i]+=blocksize/ sizeof(char);
                        heads_info[i][head_index[i]++]=file_offset[i];
                        if(head_index[i]>=blocksize){
                            fwrite(heads_info[i], sizeof(char),blocksize,head_files[i]);
                            memset( heads_info[i] , 0 , blocksize*sizeof(char) );
                            head_index[i]=0;
                        }
                    }
                    break;}
                case AVRO_STRING:{
                    string tmp=record->fieldAt(i).value<string>();
                    if((data_index[i]+tmp.length()+1)>blocksize){
                        fwrite(data_buffers[i], sizeof(char),blocksize,data_files[i]);
                        block_num[i]++;
                        memset( data_buffers[i] , 0 , blocksize*sizeof(char) );
                        heads_info[i][head_index[i]++]=strl[i];
                        file_offset[i]+=strl[i];
                        heads_info[i][head_index[i]++]=file_offset[i];
                        data_index[i]=0;
                        strl[i]=0;
                        if(head_index[i]>=blocksize){
                            fwrite(heads_info[i], sizeof(int),blocksize,head_files[i]);
                            memset( heads_info[i] , 0 , blocksize*sizeof(int) );
                            head_index[i]=0;
                        }
                    }
                    std::strcpy(&data_buffers[i][data_index[i]], tmp.c_str());
                    data_index[i]+= tmp.length()+1;
                    strl[i]++;
                    break;}
                case AVRO_ARRAY:{
                    int tmp=record->fieldAt(i).value<GenericArray>().value().size();
                    *(int*)(&data_buffers[i][data_index[i]])=tmp;
                    data_index[i]+= sizeof(int);
                    if(data_index[i]>=blocksize){
                        data_index[i]=0;
                        fwrite(data_buffers[i], sizeof(char),blocksize,data_files[i]);
                        block_num[i]++;
                        memset( data_buffers[i] , 0 , blocksize*sizeof(char) );
                        heads_info[i][head_index[i]++]=blocksize/ sizeof(int);
                        file_offset[i]+=blocksize/ sizeof(int);
                        heads_info[i][head_index[i]++]=file_offset[i];
                        if(head_index[i]>=blocksize){
                            fwrite(heads_info[i], sizeof(int),blocksize,head_files[i]);
                            memset( heads_info[i] , 0 , blocksize*sizeof(int) );
                            head_index[i]=0;
                        }
                    }
                    break;}
            }
        }

    }

    void writeRest(){
        for (int k = 0; k <column_num ; ++k) {
            if(data_index[k]!=0){
                fwrite(data_buffers[k], sizeof(char),blocksize,data_files[k]);
                block_num[k]++;
            }
            if(head_index[k]!=0){
                fwrite(heads_info[k], sizeof(int),blocksize,head_files[k]);
            }
        }

        for (int l = 0; l < column_num; ++l) {
            fflush(data_files[l]);
            fflush(head_files[l]);
            fclose(data_files[l]);
            fclose(head_files[l]);
        }
    }

    void mergeFiles(){
        for (int i = 0; i <column_num ; ++i) {
            head_files[i]=fopen((path+"/file"+to_string(i)+".head").data(),"rb");
            data_files[i]=fopen((path+"/file"+to_string(i)+".data").data(),"rb");
        }
        fstream fo;
        fo.open(path+"/fileout.dat", ios_base::out | ios_base::binary);
        long* foffsets=new long[column_num];
        int rowcount=file_offset[0];
        fo.write((char *) &blocksize, sizeof(blocksize));
        fo.write((char *) &rowcount, sizeof(rowcount));
        fo.write((char *) &column_num, sizeof(column_num));
        //fo << schema ;
        //metadata
        long* result=new long[column_num];
        std::vector<int> bc(2);
        for (int j = 0; j <column_num ; ++j) {
            fo.write((char *) &block_num[j], sizeof(int));
            foffsets[j]=fo.tellg();
            fo.write((char *) &foffsets[j], sizeof(long));
            for (int i = 0; i < block_num[j]; ++i) {
                fread(&bc[0], sizeof bc[0], bc.size(), head_files[j]);
                fo.write((char *) &bc[0], sizeof bc[0]);
                fo.write((char *) &bc[1], sizeof bc[1]);
            }
        }
        result[0]=fo.tellg();
        fo.close();
        FILE* fp=fopen((path+"/fileout.dat").data(),"ab+");
        char* buffer=new char[blocksize];
        long* tmpl=(long*) buffer;
        for (int j = 0; j <column_num ; ++j) {
            if(j!=0)result[j]=ftell(fp);
            for (int i = 0; i < block_num[j]; ++i) {
                fread(buffer, sizeof(char), blocksize, data_files[j]);
                fwrite(buffer, sizeof(char),blocksize,fp);
            }
        }
        fflush(fp);
        fclose(fp);
        fp=fopen((path+"/fileout.dat").data(),"rb+");
        for (int m = 0; m < column_num; ++m) {
            fseek(fp,foffsets[m],SEEK_SET);
            fwrite((char *) &result[m], sizeof(result[m]),1,fp);
        }
        fflush(fp);
        fclose(fp);



    }


};


#endif //CORES_BATCHFILEWRITER_H
