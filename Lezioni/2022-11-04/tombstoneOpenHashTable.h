#ifndef TOMBSTONE_OPEN_HASH_TABLE_H
#define TOMBSTONE_OPEN_HASH_TABLE_H

#include <iostream>
using namespace std;

#include "openHashTable.h"

template <class T>
class TombstoneOpenHashTable : public OpenHashTable<T>
{
private:
    virtual int computeHashFunction(T x, int i) = 0;
    T *deleted;

public:
    TombstoneOpenHashTable<T>(int tableSize) : OpenHashTable<T>(tableSize)
    {
        this->deleted = new T();
    }

    T *getDeleted()
    {
        return deleted;
    }

    TombstoneOpenHashTable<T> *insertKey(T x)
    {
        if (this->getKeyCounter() == this->getTableSize())
            return this;
        for (int i = 0; i < this->getTableSize(); i++)
        {
            int hash = computeHashFunction(x, i);
            if (this->getTable()[hash] == NULL || this->getTable()[hash] == this->getDeleted())
            {
                this->getTable()[hash] = new T(x);
                this->increaseKeyCounter();
                return this;
            }
        }
        return this;
    }

    int searchKey(T x)
    {
        if (this->getKeyCounter() == 0)
            return -1;
        for (int iterator = 0; iterator < this->getTableSize(); iterator++)
        {
            int hash = computeHashFunction(x, iterator);
            if (this->getTable()[hash] == NULL)
                return -1;
            if (this->getTable()[hash] != this->getDeleted() && *(this->getTable()[hash]) == x)
                return hash;
        }
        return -1;
    }

    TombstoneOpenHashTable<T> *deleteKey(T x)
    {
        int position = searchKey(x);
        if (position > -1)
        {
            delete this->getTable()[position];
            this->getTable()[position] = this->getDeleted();
            this->decreaseKeyCounter();
        }
        return this;
    }

    void print()
    {
        for (int i = 0; i < this->getTableSize(); i++)
        {
            cout << i;
            if (this->getTable()[i] != this->getDeleted() && this->getTable()[i])
                cout << "-> "
                     << "[" << *(this->getTable()[i]) << "]";
            else
                cout << "-> []";
            cout << endl;
        }
        cout << endl;
    }
};

#endif