#ifndef COUNTING_SORT_IN_PLACE_H
#define COUNTING_SORT_IN_PLACE_H

#include <iostream>
using namespace std;

template <typename T>
void countingSortInPlace(T *array, int size)
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
    T *frequencyArray = new T[range];

    for (int i = 0; i < range; i++)
    {
        frequencyArray[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        frequencyArray[array[i] - min]++;
    }

    int j = 0;

    for (int i = 0; i < range; i++)
        while (frequencyArray[i] > 0)
        {
            array[j] = i + min;
            frequencyArray[i]--;
            j++;
        }

    delete[] frequencyArray;
}
#endif