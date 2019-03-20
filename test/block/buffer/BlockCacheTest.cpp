//
// Created by Michael on 2018/12/2.
//
#include "BlockCache.h"
#include "utils.h"

using namespace std;

//#define BLOCK_COUNT 7680

//#define BLOCK_LIMIT 1024*1024

#define BLOCK_COUNT 1024

#define BLOCK_LIMIT 64

#define FILTERING true

#define FILTERINGRATE 0.5

int main(int argc, char **argv) {
    if(strcmp(argv[1], "st")==0){
//        FILE *fp = fopen("./text.dat", "wb+");
//        ifstream in(argv[2]);
//        char* _cache=(char*)calloc(BLOCK_LIMIT, sizeof(char));
//        PrimitiveBlock<char> *intBlock = new PrimitiveBlock<char>(fp, _cache, BLOCK_LIMIT);
//        short* l=(short*)_cache;
//        string line;
//        short length=2;
//        int amount=0;
//        int i=0;
//        char *tmp=new char[(int)BLOCK_LIMIT];
//        if(in) // 有该文件
//        {
//            while (getline (in, line)) // line中不包括每行的换行符
//            {
//                if((length+1)>BLOCK_LIMIT){
//                    char* str=(char *)(l+i+1);
//                    std::strncpy((char *)str,tmp,amount+1);
//                    l[0]=i;
//                    intBlock->appendToFile();
//                    memset(tmp,0,BLOCK_LIMIT);
//                    std::strcpy(tmp,(char*)line.c_str());
//                    l[1]=line.length();
//                    amount=line.length();
//                    i=1;
//                    length=2;
//                }
//                else{strcat(tmp,(char*)line.c_str());
//                l[i+1]=line.length();
//                amount+=line.length();
//                length+=l[i+1]+2;
//                i++;}
//            }
//
//        }
//        else // 没有该文件
//        {
//            cout <<"no such file" << endl;
//        }
////
////        for (int i = 0; i <BLOCK_COUNT ; ++i) {
////            intBlock->set_teststring();
////            intBlock->appendToFile();
////        }
////        for (int i = 0; i <BLOCK_COUNT ; ++i) {
////            intBlock->loadFromFile();
////            intBlock->get_teststring();
////        }
//        fflush(fp);
//        fclose(fp);
//        delete intBlock;
    }
    else if(strcmp(argv[1], "w")==0){
        if(strcmp(argv[2], "l")==0){FILE *fp = fopen("./text.dat", "wb+");
            PrimitiveBlock<long> *intBlock = new PrimitiveBlock<long>(fp, 0L,0, BLOCK_LIMIT);
            unsigned long long total = 0;
            Tracer tracer;
            tracer.startTime();
            for (int k = 0; k < BLOCK_COUNT; k++) {
                for (int i = 0; i < BLOCK_LIMIT/ sizeof(long); i++) {
                    intBlock->set(i, k * BLOCK_LIMIT + i);
                    total += k * BLOCK_LIMIT + i;
                }
                intBlock->appendToFile();
            }
            cout << "Ingestion: " << tracer.getRunTime() << endl;
            fflush(fp);
            fclose(fp);
            delete intBlock;}
        else if(strcmp(argv[2], "i")==0){ FILE *fp = fopen("./text.dat", "wb+");
            PrimitiveBlock<int> *intBlock = new PrimitiveBlock<int>(fp, 0L,0, BLOCK_LIMIT);
            unsigned long long total = 0;
            Tracer tracer;
            tracer.startTime();
            for (int k = 0; k < BLOCK_COUNT; k++) {
                for (int i = 0; i < BLOCK_LIMIT/ sizeof(int); i++) {
                    intBlock->set(i, k * BLOCK_LIMIT + i);
                    total += k * BLOCK_LIMIT + i;
                }
                intBlock->appendToFile();
            }
            cout << "Ingestion: " << tracer.getRunTime() << endl;
            fflush(fp);
            fclose(fp);
            delete intBlock;}
        else if(strcmp(argv[2], "s")==0){ FILE *fp = fopen("./text.dat", "wb+");
            PrimitiveBlock<char*> *intBlock = new PrimitiveBlock<char*>(fp, 0L,1024 * 1024, BLOCK_LIMIT);
            unsigned long long total = 0;
            Tracer tracer;
            tracer.startTime();
            for (int k = 0; k < BLOCK_COUNT; k++) {
                for (int i = 0; i < BLOCK_LIMIT/16; i++) {
                    intBlock->set(16*i, "mytest string");
                    total += k * BLOCK_LIMIT + i;
                }
                intBlock->appendToFile();
            }
            cout << "Ingestion: " << tracer.getRunTime() << endl;
            fflush(fp);
            fclose(fp);
            delete intBlock;}
   }
    else if(strcmp(argv[1], "r") == 0){
        if(strcmp(argv[2], "l")==0){
            FILE *fp = fopen("./text.dat", "rb+");
            unsigned long long verify = 0;
            PrimitiveBlock<long>* intBlock = new PrimitiveBlock<long>(fp, 0L, 0, BLOCK_LIMIT);
            unsigned long long total = 0;
            Tracer tracer;
            tracer.startTime();
            unsigned long long count = 0;
            for (int k = 0; k < BLOCK_COUNT; k++) {
                unsigned long long filter = BLOCK_LIMIT *BLOCK_LIMIT*FILTERINGRATE / sizeof(long);
                intBlock->loadFromFile();
                for (int i = 0; i < BLOCK_LIMIT/ sizeof(long); i++) {
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
        else if(strcmp(argv[2], "i")==0){
            FILE *fp = fopen("./text.dat", "rb+");
            unsigned long long verify = 0;
            PrimitiveBlock<int>* intBlock = new PrimitiveBlock<int>(fp, 0L, 0, BLOCK_LIMIT);
            unsigned long long total = 0;
            Tracer tracer;
            tracer.startTime();
            unsigned long long count = 0;
            unsigned long long filter = BLOCK_LIMIT *BLOCK_LIMIT*FILTERINGRATE / sizeof(int);
            for (int k = 0; k < BLOCK_COUNT; k++) {
                intBlock->loadFromFile();
                for (int i = 0; i < BLOCK_LIMIT/ sizeof(int); i++) {
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
        }else if(strcmp(argv[2], "s")==0){
            FILE *fp = fopen("./text.dat", "rb+");
            char* verify = 0;
            PrimitiveBlock<char*>* intBlock = new PrimitiveBlock<char*>(fp, 0L,0, BLOCK_LIMIT);
            unsigned long long total = 0;
            Tracer tracer;
            tracer.startTime();
            unsigned long long count = 0;
            for (int k = 0; k < BLOCK_COUNT; k++) {
                intBlock->loadFromFile();
                for (int i = 0; i < BLOCK_LIMIT/16; i++) {
                    if (FILTERING) {
//                        if (intBlock->get(i) > filter) {
//                            count++;
//                        }
                    } else {
                        verify = intBlock->get(16*i);
                        cout<<verify<<endl;
                    }
                }
            }
            cout << "Load: " << tracer.getRunTime() << "\t" << total << "<->" << count << "<->" << verify << endl;
            fclose(fp);
            delete intBlock;}else if(strcmp(argv[2], "i")==0){
            FILE *fp = fopen("./text.dat", "rb+");
            unsigned long long verify = 0;
            PrimitiveBlock<int>* intBlock = new PrimitiveBlock<int>(fp, 0L, 0, BLOCK_LIMIT);
            unsigned long long total = 0;
            Tracer tracer;
            tracer.startTime();
            unsigned long long count = 0;
            unsigned long long filter = BLOCK_LIMIT *BLOCK_LIMIT*FILTERINGRATE ;
            for (int k = 0; k < BLOCK_COUNT; k++) {
                intBlock->loadFromFile();
                for (int i = 0; i < BLOCK_LIMIT; i++) {
                    if (FILTERING) {
                        if (intBlock->get(i) > filter) {
                            count++;
                        }
                    } else {
                        verify+= intBlock->get(i);
                    }
                }
            }
            cout << "Load: " << tracer.getRunTime() << "\t" << total << "<->" << count << "<->" << verify << endl;
            fclose(fp);
            delete intBlock;}}
    return 0;
}
