#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "maxBinaryHeap.h"
#include <sstream>

template <class T>
class MaxHeap : public MaxBinaryHeap<T>
{
public:
    double compare(T *a, T *b)
    {
        return (*a) - (*b);
    }

    void printKey(int i) const
    {
        cout << *(this->getPriorityQueue())[i] << " ";
    }

    string printKeyString(int i) const
    {
        stringstream str;
        str << *(this->getPriorityQueue())[i] << " ";
        return str.str();
    }
    MaxHeap(int size) : MaxBinaryHeap<T>(size) {}
    MaxHeap(T **A, int size) : MaxBinaryHeap<T>(A, size) {}
};

#endif