#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <sstream>

template <class H>
class MaxHeap
{
private:
    Terne<H> **array;
    int size;
    int heapsize;
    int cont;
    int left(int i) { return i << 1; }
    int right(int i) { return (i << 1) | 1; }
    int parent(int i) { return i >> 1; }
    stringstream s;

    void swap(int i, int j)
    {
        Terne<H> *tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    void max_heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int max = i;
        if (l <= heapsize && *array[l] > *array[max])
            max = l;
        if (r <= heapsize && *array[r] > *array[max])
            max = r;
        if (max != i)
        {
            swap(i, max);
            max_heapify(max);
        }
        if (heapsize >= 1)
            cont++;
    }

public:
    MaxHeap(Terne<H> **arr, int len)
    {
        array = new Terne<H> *[len + 1];

        for (int i = 1; i <= len; i++)
        {
            array[i] = arr[i - 1];
        }

        size = len + 1;
        heapsize = len;
        cont = 0;
        s.str("");
    }

    void build_heap()
    {
        for (int i = heapsize / 2; i > 0; i--)
        {
            max_heapify(i);
        }
    }

    void extract()
    {
        swap(1, heapsize);
        heapsize--;
        max_heapify(1);
    }

    int getHeapifyCount()
    {
        return cont;
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

    void enqueue(H elem)
    {
        heapsize++;
        array[heapsize] = elem;
        int i = heapsize;
        while (i > 1 && array[parent(i)] < array[i])
        {
            swap(parent(i), i);
            i = parent(i);
        }
    }

    string print()
    {
        for (int i = 1; i < size; i++)
            s << *array[i] << " ";
        s << endl;
        return s.str();
    }
};
#endif