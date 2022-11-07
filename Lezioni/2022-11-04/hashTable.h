#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
using namespace std;

template <class T>
class HashTable
{
public:
    virtual HashTable<T> *insertKey(T x) = 0;
    virtual int searchKey(T x) = 0;
    virtual HashTable<T> *deleteKey(T x) = 0;
    virtual void print() = 0;
};

#endif