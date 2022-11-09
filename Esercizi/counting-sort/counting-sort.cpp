#include <iostream>
#include <fstream>
using namespace std;

#include "countingSort.h"

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
        return 0;
    }

    int dim = 0;
    while (fileInput.good())
    {
        fileInput >> dim;

        int *arr = new int[dim]{0};

        for (int i = 0; i < dim; i++)
        {
            fileInput >> arr[i];
        }

        int max = arr[0];
        int min = arr[0];

        for (int i = 0; i < dim; i++)
        {
            if (max < arr[i])
            {
                max = arr[i];
            }

            else if (min > arr[i])
            {
                min = arr[i];
            }
        }

        int range = max - min + 1;
        int *C = countingSort<int>(arr, dim);

        for (int i = 0; i < range; i++)
        {
            fileOutput << C[i] << " ";
        }

        for (int i = 0; i < dim; i++)
        {
            fileOutput << arr[i] << " ";
        }

        fileOutput << endl;
    }
}
