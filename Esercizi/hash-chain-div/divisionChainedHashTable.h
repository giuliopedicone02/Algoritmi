#ifndef DIVISION_CHAINED_HASH_TABLE_H
#define DIVISION_CHAINED_HASH_TABLE_H

#include "chainedHashTable.h"

template <class T>
class DivisionChainedHashTable : public ChainedHashTable<T>
{
private:
    int computeHashFunction(T x)
    {
        int h = ((int)x % this->getSlotNumber());
        return h;
    }

public:
    DivisionChainedHashTable<T>(int edge_number) : ChainedHashTable<T>(edge_number) {}
};

#endif