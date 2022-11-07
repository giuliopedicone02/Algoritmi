#ifndef LINEAR_DELETE_SHIFT_OPEN_HASH_TABLE_H
#define LINEAR_DELETE_SHIFT_OPEN_HASH_TABLE_H

#include <iostream>
using namespace std;

#include "deleteShiftOpenHashTable.h"
#include "linearHashFunction.h"

template <class T>
class LinearDeleteShiftOpenHashTable : public DeleteShiftOpenHashTable<T>, LinearHashFunction<T>
{
protected:
    int computeHashFunction(T x, int i)
    {
        return LinearHashFunction<T>::computeHashFunction(x, i, this->getTableSize());
    }

public:
    LinearDeleteShiftOpenHashTable(int tableSize) : DeleteShiftOpenHashTable<T>(tableSize) {}
};

#endif