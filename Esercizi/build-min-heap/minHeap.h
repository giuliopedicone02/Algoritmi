#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "minBinaryHeap.h"
#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class MinHeap : public MinBinaryHeap<T>
{
public:
    MinHeap(int size) : MinBinaryHeap<T>(size) {}
    MinHeap(T **A, int size) : MinBinaryHeap<T>(A, size) {}
    double compare(T *a, T *b)
    {
        return (*b) - (*a);
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
};

#endif