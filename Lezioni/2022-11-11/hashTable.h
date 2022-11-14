#ifndef HASH_TABLE_H
#define HASH_TABLE_H

template <class T>
class HashTable
{
public:
    virtual HashTable<T> *insertKey(T x) = 0;
    virtual HashTable<T> *deleteKey(T key) = 0;
    virtual int searchKey(T key) = 0;
};

#endif