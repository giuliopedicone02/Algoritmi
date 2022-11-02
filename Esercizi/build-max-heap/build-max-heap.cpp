#include <iostream>
#include <fstream>
#include <typeinfo>

#include "maxHeap.h"
using namespace std;

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
    int dim, i_val = 0;
    double d_val = 0.0;
    char c_val = '\0';
    bool b_val = false;

    while (fileInput.good())
    {
        fileInput >> type >> dim;

        if (type == "int")
        {
            MaxHeap<int> *int_heap = new MaxHeap<int>(dim);

            for (int i = 0; i < dim; i++)
            {
                fileInput >> i_val;
                int_heap->enqueue(i_val);
            }

            fileOutput << int_heap->printString();
        }

        if (type == "double")
        {
            MaxHeap<double> *double_heap = new MaxHeap<double>(dim);

            for (int i = 0; i < dim; i++)
            {
                fileInput >> d_val;
                double_heap->enqueue(d_val);
            }

            fileOutput << double_heap->printString();
        }

        if (type == "char")
        {
            MaxHeap<char> *char_heap = new MaxHeap<char>(dim);

            for (int i = 0; i < dim; i++)
            {
                fileInput >> c_val;
                char_heap->enqueue(c_val);
            }

            fileOutput << char_heap->printString();
        }

        if (type == "bool")
        {
            MaxHeap<bool> *bool_heap = new MaxHeap<bool>(dim);

            for (int i = 0; i < dim; i++)
            {
                fileInput >> b_val;
                bool_heap->enqueue(b_val);
            }

            fileOutput << bool_heap->printString();
        }
    }
}