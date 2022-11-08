#ifndef MIN_BINARY_HEAP_H
#define MIN_BINARY_HEAP_H

#include "binaryHeap.h"

template <class T>
class MinBinaryHeap : public BinaryHeap<T>
{
public:
    MinBinaryHeap(int size) : BinaryHeap<T>(size) {}
    MinBinaryHeap(T **A, int size) : BinaryHeap<T>(A, size) {}
    virtual double compare(T *a, T *b) = 0;
    virtual void printKey(int i) const = 0;
    T *extractMin()
    {
        return BinaryHeap<T>::extract();
    }
    void decreaseKey(int i, T k)
    {
        return BinaryHeap<T>::modify(i, k);
    }
};

#endif