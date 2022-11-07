#ifndef QUADRATIC_TOMBSTONE_OPEN_HASH_TABLE_H
#define QUADRATIC_TOMBSTONE_OPEN_HASH_TABLE_H

#include <iostream>
using namespace std;

#include "tombstoneOpenHashTable.h"
#include "quadraticHashFunction.h"

template <class T>
class QuadraticTombstoneOpenHashTable : public TombstoneOpenHashTable<T>, QuadraticHashFunction<T>
{
private:
    int computeHashFunction(T x, int i)
    {
        return QuadraticHashFunction<T>::computeHashFunction(x, i, this->getTableSize());
    }

public:
    QuadraticTombstoneOpenHashTable(int tableSize) : TombstoneOpenHashTable<T>(tableSize), QuadraticHashFunction<T>(1 / 2, 1 / 2) {}
};

#endif