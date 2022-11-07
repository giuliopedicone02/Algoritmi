#ifndef DELETE_SHIFT_OPEN_HASH_TABLE_H
#define DELETE_SHIFT_OPEN_HASH_TABLE_H

#include <iostream>
using namespace std;

#include "openHashTable.h"

template <class T>
class DeleteShiftOpenHashTable : public OpenHashTable<T>
{
private:
    virtual int computeHashFunction(T x, int i) = 0;

public:
    DeleteShiftOpenHashTable<T>(int tableSize) : OpenHashTable<T>(tableSize) {}

    DeleteShiftOpenHashTable<T> *insertKey(T x)
    {
        if (this->getKeyCounter() == this->getTableSize())
            return this;
        for (int i = 0; i < this->getTableSize(); i++)
        {
            int hash = computeHashFunction(x, i);
            if (this->getTable()[hash] == NULL)
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
            if (*(this->getTable()[hash]) == x)
                return hash;
        }
        return -1;
    }

    DeleteShiftOpenHashTable<T> *deleteKey(T x)
    {
        if (this->getKeyCounter() == 0)
            return this;

        for (int iterator = 0; iterator < this->getTableSize(); iterator++)
        {
            int hash = computeHashFunction(x, iterator);
            if (this->getTable()[hash] == NULL)
                return this;
            if (*(this->getTable()[hash]) == x)
            {
                delete this->getTable()[hash];
                this->getTable()[hash] = NULL;
                this->decreaseKeyCounter();
                iterator++;
                for (; iterator < this->getTableSize(); iterator++)
                {
                    int hash2 = computeHashFunction(x, iterator);
                    this->getTable()[hash] = (this->getTable()[hash2]);
                    if (this->getTable()[hash2] == NULL)
                        return this;
                    hash = hash2;
                }
                return this;
            }
        }
        return this;
    }

    void print()
    {
        for (int i = 0; i < this->getTableSize(); i++)
        {
            cout << i;
            if (this->getTable()[i])
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