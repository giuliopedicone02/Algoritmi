#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include <iostream>
using namespace std;

template <typename T>
void print(T *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

template <typename T>
void countingSort(T *array, int size)
{
    T max = array[0];
    T min = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }

        int range = max - min + 1;
        int *freq = new int[range]{0};
        int *tmp = new int[size];

        for (int i = 0; < size; i++)
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
            inputArray[i] = tmp[i];
        }

        delete[] freq;
        delete[] tmp;
    }
}
#endif