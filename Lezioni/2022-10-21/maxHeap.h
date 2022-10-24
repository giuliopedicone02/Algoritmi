#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "maxBinaryHeap.h"

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
    MaxHeap(int size) : MaxBinaryHeap<T>(size) {}
    MaxHeap(T **A, int size) : MaxBinaryHeap<T>(A, size) {}
};

#endif