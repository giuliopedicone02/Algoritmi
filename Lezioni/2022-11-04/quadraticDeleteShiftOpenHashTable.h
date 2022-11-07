#ifndef QUADRATIC_DELETE_SHIFT_OPEN_HASH_TABLE_H
#define QUADRARIC_DELETE_SHIFT_OPEN_HASH_TABLE_H

#include <iostream>
using namespace std;

#include "deleteShiftOpenHashTable.h"
#include "quadraticHashFunction.h"

template <class T>
class QuadraticDeleteShiftOpenHashTable : public DeleteShiftOpenHashTable<T>, QuadraticHashFunction<T>
{
private:
    int computeHashFunction(T x, int i)
    {
        return QuadraticHashFunction<T>::computeHashFunction(x, i, this->getTableSize());
    }

public:
    QuadraticDeleteShiftOpenHashTable(int tableSize) : DeleteShiftOpenHashTable<T>(tableSize), QuadraticHashFunction<T>(1 / 2, 1 / 2) {}
};

#endif