#include <iostream>
#include <fstream>
#include "minHeap.h"
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

    int dim, i_val = 0;
    double d_val = 0.0;
    char c_val = '\0';
    bool b_val = false;
    string type = "";
    string s = "";

    while (fileInput.good())
    {
        fileInput >> type >> dim;

        if (type == "int")
        {
            MinHeap<int> *int_heap = new MinHeap<int>(dim);

            for (int i = 0; i < dim; i++)
            {
                fileInput >> i_val;

                int_heap->enqueue(i_val);
            }

            int_heap->print();
            fileOutput << int_heap->printString();
        }

        if (type == "double")
        {
            MinHeap<double> *double_heap = new MinHeap<double>(dim);

            for (int i = 0; i < dim; i++)
            {
                fileInput >> d_val;

                double_heap->enqueue(d_val);
            }

            double_heap->print();
            fileOutput << double_heap->printString();
        }

        if (type == "char")
        {
            MinHeap<char> *char_heap = new MinHeap<char>(dim);

            for (int i = 0; i < dim; i++)
            {
                fileInput >> c_val;

                char_heap->enqueue(c_val);
            }

            char_heap->print();
            fileOutput << char_heap->printString();
        }

        if (type == "bool")
        {
            MinHeap<bool> *bool_heap = new MinHeap<bool>(dim);

            for (int i = 0; i < dim; i++)
            {
                fileInput >> b_val;

                bool_heap->enqueue(b_val);
            }

            bool_heap->print();
            fileOutput << bool_heap->printString();
        }
    }
}
