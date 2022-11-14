#ifndef MOLTIPLICATION_CHAINED_HASH_TABLE_H
#define MOLTIPLICATION_CHAINED_HASH_TABLE_H

#include "chainedHashTable.h"

template <class T>
class MultiplicationChainedHashTable : public ChainedHashTable<T>
{
private:
    double c;
    int computeHashFunction(T x)
    {
        double y = x * c;
        double a = y - (int)y;
        int h = (int)(a * this->getSlotNumber());
        return h;
    }

public:
    MultiplicationChainedHashTable(int edge_number) : ChainedHashTable<T>(edge_number)
    {
        c = 0.7;
    }
};

#endif