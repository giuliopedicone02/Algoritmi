#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include "priorityQueue.h"
#include <iostream>
using namespace std;
template <typename T>
class BinaryHeap : public PriorityQueue<T>
{
private:
    T **queue;
    int heapsize;
    int queueLength;

    int left(int i)
    {
        return 2 * i;
    }

    int right(int i)
    {
        return 2 * i + 1;
    }

    int parent(int i)
    {
        return i / 2;
    }

    void swap(int i, int j)
    {
        T *tmp = queue[i];
        queue[i] = queue[j];
        queue[j] = tmp;
    }

    void heapify(int index)
    {
        while (index <= heapsize / 2)
        {
            int m = index;
            int l = left(index);
            int r = right(index);

            if (l <= heapsize && compare(queue[m], queue[l]) < 0)
            {
                m = l;
            }

            if (r <= heapsize && compare(queue[m], queue[r]) < 0)
            {
                m = r;
            }

            if (m == index)
            {
                break;
            }

            swap(index, m);
            index = m;
        }
    }

    void moveUpKey(int i)
    {
        while (i > 1 && compare(queue[i], queue[parent(i)]) > 0)
        {
            swap(i, parent(i));
            i = parent(i);
        }
    }

public:
    virtual double compare(T *a, T *b) = 0;
    virtual void printKey(int i) const = 0;
    virtual string printKeyString(int i) const = 0;

    int size() const
    {
        return heapsize;
    }

    BinaryHeap(int size)
    {
        queue = new T *[size + 1];
        queueLength = size + 1;
        heapsize = 0;
    }

    BinaryHeap(T **V, int size)
    {
        queue = V;
        queueLength = size;
        heapsize = size - 1;
    }

    void buildHeap()
    {
        for (int i = heapsize / 2; i >= 0; i--)
        {
            heapify(i);
        }
    }

    T *extract()
    {
        if (heapsize == 0)
        {
            return nullptr;
        }

        swap(1, heapsize);
        heapsize--;
        heapify(1);
        return queue[heapsize + 1];
    }

    T **getPriorityQueue() const
    {
        return queue;
    }

    void modify(int i, T k)
    {
        if (i < 1 || i > heapsize)
        {
            return;
        }

        if (compare(queue[i], &k) >= 0)
        {
            return;
        }

        delete queue[i];
        queue[i] = new T(k);

        moveUpKey(i);
        return;
    }

    BinaryHeap<T> *enqueue(T x)
    {
        if (heapsize == queueLength - 1)
        {
            return this;
        }

        heapsize += 1;
        queue[heapsize] = new T(x);
        int i = heapsize;
        moveUpKey(i);
        return this;
    }

    void sort()
    {
        int count = heapsize;
        for (int i = 0; i < count; i++)
        {
            extract();
        }
        heapsize = count;
    }

    void print() const
    {
        for (int i = 1; i <= this->size(); i++)
            printKey(i);
        cout << endl;
    }

    string printString() const
    {
        string str = "";
        for (int i = 1; i <= this->size(); i++)
            str += printKeyString(i);
        str += "\n";

        return str;
    }
};
#endif