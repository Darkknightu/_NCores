//
// Created by Michael on 2018/12/2.
//
#include "BlockCache.h"
#include "utils.h"

using namespace std;

//#define BLOCK_COUNT 7680

//#define BLOCK_LIMIT 1024*1024

#define BLOCK_COUNT 1024

#define BLOCK_LIMIT 1024

#define FILTERING false

int main(int argc, char **argv) {
    if(strcmp(argv[1], "w")==0){
        if(strcmp(argv[2], "l")==0){FILE *fp = fopen("./text.dat", "wb+");
            PrimitiveBlock<long> *intBlock = new PrimitiveBlock<long>(fp, 0L,0, BLOCK_LIMIT);
            unsigned long long total = 0;
            Tracer tracer;
            tracer.startTime();
            for (int k = 0; k < BLOCK_COUNT; k++) {
                for (int i = 0; i < BLOCK_LIMIT; i++) {
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
                for (int i = 0; i < BLOCK_LIMIT; i++) {
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
                unsigned long long filter = k * BLOCK_LIMIT + BLOCK_LIMIT / 2;
                intBlock->loadFromFile();
                for (int i = 0; i < BLOCK_LIMIT; i++) {
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
            for (int k = 0; k < BLOCK_COUNT; k++) {
                unsigned long long filter = k * BLOCK_LIMIT + BLOCK_LIMIT / 2;
                intBlock->loadFromFile();
                for (int i = 0; i < BLOCK_LIMIT; i++) {
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
                unsigned long long filter = k * BLOCK_LIMIT + BLOCK_LIMIT / 2;
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
            for (int k = 0; k < BLOCK_COUNT; k++) {
                unsigned long long filter = k * BLOCK_LIMIT + BLOCK_LIMIT / 2;
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
