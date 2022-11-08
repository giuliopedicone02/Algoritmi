#ifndef MAX_BINARY_HEAP_H
#define MAX_BINARY_HEAP_H

#include "binaryHeap.h"
template <class T>
class MaxBinaryHeap : public BinaryHeap<T>
{
public:
    MaxBinaryHeap(int size) : BinaryHeap<T>(size) {}
    MaxBinaryHeap(T **A, int size) : BinaryHeap<T>(A, size) {}

    virtual double compare(T *a, T *b) = 0;
    virtual void printKey(int i) const = 0;

    T *extractMax()
    {
        return BinaryHeap<T>::extract();
    }
    void increaseKey(int i, T k)
    {
        return BinaryHeap<T>::modify(i, k);
    }
};

#endif