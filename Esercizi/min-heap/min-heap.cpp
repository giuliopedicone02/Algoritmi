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
                fileInput >> s;

                if (s == "extract")
                {
                    int_heap->extract();
                }
                else
                {
                    s = s.substr(2, s.length());
                    i_val = stoi(s);
                    int_heap->enqueue(i_val);
                }
            }

            cout << int_heap->getHeapifyCount() << " ";
            int_heap->print();
        }

        if (type == "double")
        {
            MinHeap<double> *double_heap = new MinHeap<double>(dim);

            for (int i = 0; i < dim; i++)
            {
                fileInput >> s;

                if (s == "extract")
                {
                    double_heap->extract();
                }
                else
                {
                    s = s.substr(2, s.length());
                    d_val = stod(s);
                    double_heap->enqueue(d_val);
                }
            }

            cout << double_heap->getHeapifyCount() << " ";
            double_heap->print();
        }

        if (type == "char")
        {
            MinHeap<char> *char_heap = new MinHeap<char>(dim);

            for (int i = 0; i < dim; i++)
            {
                fileInput >> s;

                if (s == "extract")
                {
                    char_heap->extract();
                }
                else
                {
                    c_val = s[s.length() - 1];
                    char_heap->enqueue(c_val);
                }
            }

            cout << char_heap->getHeapifyCount() << " ";

            char_heap->print();
        }

        if (type == "bool")
        {
            MinHeap<bool> *bool_heap = new MinHeap<bool>(dim);

            for (int i = 0; i < dim; i++)
            {
                fileInput >> s;

                if (s == "extract")
                {
                    bool_heap->extract();
                }
                else
                {
                    s = s.at(s.length() - 1);

                    if (s == "0")
                    {
                        b_val = false;
                    }
                    else if (s == "1")
                    {
                        b_val = true;
                    }

                    bool_heap->enqueue(b_val);
                }
            }

            cout << bool_heap->getHeapifyCount() << " ";

            bool_heap->print();
        }
    }
}