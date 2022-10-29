#include <iostream>
#include "countingSort.h"
#include "countingSortinPlace.h"
using namespace std;

template <typename T>
void printArr(T *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {12, 2, 8, 56, 42, 89, 25};

    cout << "Array non ordinato: ";
    printArr<int>(arr, 7);

    cout << "\nArray ordinato con countingSort(): ";
    countingSort<int>(arr, 7);
    printArr<int>(arr, 7);

    cout << "\nArray ordinato con countingSortInPlace(): ";
    countingSortInPlace<int>(arr, 7);
    printArr<int>(arr, 7);
}