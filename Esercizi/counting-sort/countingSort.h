#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include <iostream>
using namespace std;

template <typename T>
T *countingSort(T *array, int size)
{
    T max = array[0];
    T min = array[0];
    for (int i = 1; i < size; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }

        else if (min > array[i])
        {
            min = array[i];
        }
    }

    int range = max - min + 1;

    T *tmp = new T[size];
    T *freq = new T[range];

    for (int i = 0; i < range; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        freq[array[i] - min]++;
    }

    for (int i = 1; i < range; i++)
    {
        freq[i] += freq[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        tmp[freq[array[i] - min] - 1] = array[i];
        freq[array[i] - min]--;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = tmp[i];
    }

    return freq;
    delete[] freq;
    delete[] tmp;
}

#endif