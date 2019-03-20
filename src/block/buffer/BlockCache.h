#pragma once

#include <iostream>
#include <fstream>
#include <limits>
#include <cstring>
#include "FileOperations.h"
#include "CoresIterator.h"
#include "CoresAppender.h"
#include "CoresBlock.h"
#include "CoresRandomAccessor.h"

using namespace std;

namespace codec{
    template<class T> void encode(T* _cache, T value){
        *_cache=value;
    }

    template<class T> T decode(T* _cache){
        return *_cache;
    }

    template <>
    void encode(char** _cache, char* value)
    {
        *(short *)_cache=strlen(value);
        _cache+=2;
        std::strcpy((char *)_cache,value);
    }

    template <>
    char* decode(char** _cache)
    {
        short lgth= *(short *)_cache;
        _cache+=2;
        return (char*)_cache;
    }

}

template<typename type>
class PrimitiveBlock
        : public CoresIterator<type>,
          public CoresAppender<type>,
          public CoresBlock<type>,
          public CoresRandomAccesessor<type> {
    type *_cache;

    FILE *_fp;

    size_t _offset;

    int _count;

    int _limit;

    size_t _cursor;

    size_t _total;

public:
    PrimitiveBlock(FILE *fp, size_t begin, int count = 0, int limit = 1024) : _cache((type *)calloc(limit, sizeof(char))), _fp(fp),
                                                                              _offset(begin), _count(count),
                                                                              _limit(limit/(sizeof(type))),
                                                                              _cursor(0) {
        bigseek(fp, 0, SEEK_END);
        _total = bigtell(fp);
        bigseek(fp, _offset, SEEK_SET);
    }

    PrimitiveBlock(FILE *fp,char* cache, int limit = 1024) : _cache(cache), _fp(fp),
                                                                              _offset(0), _count(0),
                                                                              _limit(limit),
                                                                              _cursor(0) {
        bigseek(fp, 0, SEEK_END);
        _total = bigtell(fp);
        bigseek(fp, _offset, SEEK_SET);
    }

    void set(int idx, type value) {
        //_cache[idx] = value;
        codec::encode(&_cache[idx],value);
    }

    void set_teststring(){
        short lgth=_limit/16-1;
        *(short*)_cache=lgth;
        for (int i = 0; i < lgth; ++i) {
            ((short*)_cache)[i+1]=14;
        }
        char* tmp=(char*)((short *)_cache+lgth+1);
        for (int i = 0; i < lgth; ++i) {
            std::strcpy(tmp,"my teststring");
            tmp+=14;
        }
    }

    type get(int idx) {
        //return _cache[idx];
        return codec::decode(&_cache[idx]);
    }

    void get_teststring(){
        short * lp=(short*)_cache;
        short ll=lp[0];
        char* cp=(char*)_cache+ll*2+2;
        for (int i = 0; i < ll; ++i) {
            cp;
            cp+=lp[ll+1];
        }

    }

    void append(type value) {
        _cache[_count] = value;
        if (_count++ == _limit) {
            appendToFile();
            _offset += _count * sizeof(type);
            _count = 0;
        }
    }

    ~PrimitiveBlock() {
        delete[] _cache;
        fflush(_fp);
    }

    type *readFromFile() {
        if (bigseek(_fp, _offset, SEEK_SET) == 0) {
            fread(_cache, sizeof(type), _limit, _fp);
        } else {
            printf("Cannot seek block: %lld", _offset);
        }
        return _cache;
    }

    type *loadFromFile() {
        fread(_cache, sizeof(type), _limit, _fp);
        return _cache;
    }

    void appendToFile() {
        appendToFile(_cache);
    }

    void appendToFile(type *buf) {
        fwrite(_cache, sizeof(type), _limit, _fp);
    }

    void writeToFile() {
        if (bigseek(_fp, _offset, SEEK_SET) == 0) {
            appendToFile(_cache);
        } else {
            printf("Cannot write block: %lld", _offset);
        }
    }

    void writeToFile(type *buf, uint64_t offset, int size) {
        if (bigseek(_fp, offset, SEEK_SET) == 0) {
            fwrite(buf, sizeof(type), size, _fp);
        } else {
            printf("Cannot write block: %lld", offset);
        }
    }

    void open() {
        bigseek(_fp, _offset, SEEK_SET);
        _cursor = 0;
    }

    void wind(size_t offset) {
        _offset = offset;
        bigseek(_fp, _offset, SEEK_SET);
    }

    bool hashNext() {
        if (_cursor < _limit) {
            return true;
        }
        if (_offset >= _total) {
            return false;
        }
        size_t read = fread(_cache, sizeof(type), _limit, _fp);
        _offset += read;
        if (read > 0) {
            _cursor = 0;
            return true;
        }
        return false;
    }

    type next() {
        return _cache[_cursor++];
    }
};