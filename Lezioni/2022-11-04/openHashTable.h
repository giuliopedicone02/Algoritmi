#ifndef OPEN_HASH_TABLE_H
#define OPEN_HASH_TABLE_H

#include <iostream>
using namespace std;

#include "hashTable.h"

template <class T>
class OpenHashTable : public HashTable<T>
{
private:
    virtual int computeHashFunction(T x, int i) = 0;
    virtual OpenHashTable<T> *insertKey(T x) = 0;
    virtual OpenHashTable<T> *deleteKey(T x) = 0;
    virtual int searchKey(T x) = 0;
    int tableSize;
    int keyCounter;
    T **table;

public:
    OpenHashTable<T>(int tableSize)
    {
        table = new T *[tableSize];
        for (int i = 0; i < tableSize; i++)
            table[i] = NULL;
        this->keyCounter = 0;
        this->tableSize = tableSize;
    }

    void increaseKeyCounter()
    {
        keyCounter++;
    }

    void decreaseKeyCounter()
    {
        keyCounter--;
    }

    int getTableSize()
    {
        return tableSize;
    }

    int getKeyCounter()
    {
        return keyCounter;
    }

    T **getTable()
    {
        return table;
    }
};

#endif