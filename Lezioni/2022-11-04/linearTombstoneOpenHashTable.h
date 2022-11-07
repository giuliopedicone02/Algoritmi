#ifndef LINEAR_TOMBSTONE_OPEN_HASH_TABLE_H
#define LINEAR_TOMBSTONE_OPEN_HASH_TABLE_H

#include <iostream>
using namespace std;

#include "tombstoneOpenHashTable.h"
#include "linearHashFunction.h"

template <class T>
class LinearTombstoneOpenHashTable : public TombstoneOpenHashTable<T>, LinearHashFunction<T>
{
protected:
    int computeHashFunction(T x, int i)
    {
        return LinearHashFunction<T>::computeHashFunction(x, i, this->getTableSize());
    }

public:
    LinearTombstoneOpenHashTable(int tableSize) : TombstoneOpenHashTable<T>(tableSize) {}
};

#endif