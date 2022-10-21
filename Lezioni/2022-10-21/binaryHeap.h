#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include "priorityQueue.h"
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
        T tmp = queue[i];
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
};
#endif