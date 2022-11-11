#include <iostream>
#include <fstream>
#include <typeinfo>
#include <cstring>
#include <cmath>
#include <sstream>

using namespace std;

template <class H>
class MaxHeap
{
private:
    H *array;
    int size;

    int left(int i) { return i << 1; }
    int right(int i) { return (i << 1) | 1; }
    int parent(int i) { return i >> 1; }
    stringstream s;

    void swap(int i, int j)
    {
        H tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    void max_heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int max = i;
        if (l < size && array[l] > array[max])
            max = l;
        if (r < size && array[r] > array[max])
            max = r;
        if (max != i)
        {
            swap(i, max);
            max_heapify(max);
        }
    }

public:
    MaxHeap(H *arr, int len)
    {
        array = new H[len + 1];

        for (int i = 1; i <= len; i++)
        {
            array[i] = arr[i - 1];
        }

        size = len + 1;

        s.str("");
    }

    void build_heap()
    {
        for (int i = floor(size + 1 / 2); i >= 1; i--)
        {
            max_heapify(i);
        }
    }

    string print()
    {
        for (int i = 1; i < size; i++)
            s << array[i] << " ";
        s << endl;
        return s.str();
    }
};

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
        return 0;
    }

    string type = "";
    int dim = 0;

    while (fileInput.good())
    {
        fileInput >> type >> dim;

        if (type == "int")
        {
            int *arr = new int[dim];

            for (int i = 0; i < dim; i++)
            {
                fileInput >> arr[i];
            }

            MaxHeap<int> *int_heap = new MaxHeap<int>(arr, dim);
            int_heap->build_heap();
            fileOutput << int_heap->print();
        }

        if (type == "double")
        {
            double *arr = new double[dim];

            for (int i = 0; i < dim; i++)
            {
                fileInput >> arr[i];
            }

            MaxHeap<double> *double_heap = new MaxHeap<double>(arr, dim);
            double_heap->build_heap();
            fileOutput << double_heap->print();
        }

        if (type == "char")
        {
            char *arr = new char[dim];

            for (int i = 0; i < dim; i++)
            {
                fileInput >> arr[i];
            }

            MaxHeap<char> *char_heap = new MaxHeap<char>(arr, dim);
            char_heap->build_heap();
            fileOutput << char_heap->print();
        }

        if (type == "bool")
        {
            bool *arr = new bool[dim];

            for (int i = 0; i < dim; i++)
            {
                fileInput >> arr[i];
            }

            MaxHeap<bool> *bool_heap = new MaxHeap<bool>(arr, dim);
            bool_heap->build_heap();
            fileOutput << bool_heap->print();
        }
    }
}