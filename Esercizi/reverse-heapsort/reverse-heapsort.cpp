#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
using namespace std;

template <class H>
class MinHeap
{
private:
    H *array;
    int size;
    int heapsize;
    int cont;
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

    void min_heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int min = i;
        if (l <= heapsize && array[l] < array[min])
            min = l;
        if (r <= heapsize && array[r] < array[min])
            min = r;
        if (min != i)
        {
            swap(i, min);
            min_heapify(min);
        }
        if (heapsize >= 1)
            cont++;
    }

public:
    MinHeap(H *arr, int len)
    {
        array = new H[len + 1];

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
            min_heapify(i);
        }
    }

    void extract()
    {
        swap(1, heapsize);
        heapsize--;
        min_heapify(1);
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

    int dim = 0;
    string type = "";

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

            MinHeap<int> *int_heap = new MinHeap<int>(arr, dim);

            int_heap->build_heap();

            for (int i = 0; i < dim; i++)
            {
                int_heap->extract();
            }

            fileOutput << int_heap->getHeapifyCount() << " ";
            int_heap->sort();
            fileOutput << int_heap->print();
            // int_heap->print();
        }

        if (type == "double")
        {
            double *arr = new double[dim];

            for (int i = 0; i < dim; i++)
            {
                fileInput >> arr[i];
            }

            MinHeap<double> *double_heap = new MinHeap<double>(arr, dim);

            double_heap->build_heap();

            for (int i = 0; i < dim; i++)
            {
                double_heap->extract();
            }

            fileOutput << double_heap->getHeapifyCount() << " ";
            double_heap->sort();
            fileOutput << double_heap->print();
        }

        if (type == "char")
        {
            char *arr = new char[dim];

            for (int i = 0; i < dim; i++)
            {
                fileInput >> arr[i];
            }

            MinHeap<char> *char_heap = new MinHeap<char>(arr, dim);
            char_heap->build_heap();

            for (int i = 0; i < dim; i++)
            {
                char_heap->extract();
            }

            fileOutput << char_heap->getHeapifyCount() << " ";
            char_heap->sort();
            fileOutput << char_heap->print();

            // char_heap->print();
        }

        if (type == "bool")
        {
            bool *arr = new bool[dim];

            for (int i = 0; i < dim; i++)
            {
                fileInput >> arr[i];
            }

            MinHeap<bool> *bool_heap = new MinHeap<bool>(arr, dim);

            bool_heap->build_heap();

            for (int i = 0; i < dim; i++)
            {
                bool_heap->extract();
            }

            fileOutput << bool_heap->getHeapifyCount() << " ";

            bool_heap->sort();

            fileOutput << bool_heap->print();

            // bool_heap->print();
        }
    }
}