#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "coppie.h"
#include "maxHeap.h"
using namespace std;

template <typename T>
void print(T *arr, int dim, fstream &out)
{
    for (int i = 0; i < dim; i++)
    {
        out << arr[i] << " ";
    }
}

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
        return 0;
    }

    int dim = 0, int_val1 = 0, int_val2 = 0;
    double double_val1 = 0.0, double_val2 = 0.0;
    char char_val1 = '\0', char_val2 = '\0';
    bool bool_val1 = false, bool_val2 = false;
    string type = "";
    string num1 = " ", num2 = " ";

    for (int x = 0; x < 100; x++)
    {
        fileInput >> type >> dim;

        if (type == "int")
        {
            Coppia<int> **coppie = new Coppia<int> *[dim];

            for (int i = 0; i < dim; i++)
            {
                fileInput >> num1 >> num2;

                num1 = num1.substr(1, num1.length());
                num2 = num2.substr(0, num2.length() - 1);

                int_val1 = stoi(num1);
                int_val2 = stoi(num2);

                coppie[i] = new Coppia<int>(int_val1, int_val2);
            }

            MaxHeap<int> *int_heap = new MaxHeap<int>(coppie, dim);

            int_heap->build_heap();
            int_heap->sort();

            fileOutput << int_heap->getHeapifyCount() << " ";
            fileOutput << int_heap->print();
            // int_heap->print();
        }

        if (type == "double")
        {
            Coppia<double> **coppie = new Coppia<double> *[dim];

            for (int i = 0; i < dim; i++)
            {
                fileInput >> num1 >> num2;

                num1 = num1.substr(1, num1.length());
                num2 = num2.substr(0, num2.length() - 1);

                double_val1 = stod(num1);
                double_val2 = stod(num2);

                coppie[i] = new Coppia<double>(double_val1, double_val2);
            }
            MaxHeap<double> *double_heap = new MaxHeap<double>(coppie, dim);

            double_heap->build_heap();
            double_heap->sort();

            fileOutput << double_heap->getHeapifyCount() << " ";
            fileOutput << double_heap->print();
        }

        if (type == "char")
        {
            Coppia<char> **coppie = new Coppia<char> *[dim];

            for (int i = 0; i < dim; i++)
            {
                fileInput >> num1 >> num2;

                char_val1 = num1[1];
                char_val2 = num2[0];

                coppie[i] = new Coppia<char>(char_val1, char_val2);
            }

            MaxHeap<char> *char_heap = new MaxHeap<char>(coppie, dim);
            char_heap->build_heap();
            char_heap->sort();

            fileOutput << char_heap->getHeapifyCount() << " ";
            fileOutput << char_heap->print();

            // char_heap->print();
        }

        if (type == "bool")
        {
            Coppia<bool> **coppie = new Coppia<bool> *[dim];

            for (int i = 0; i < dim; i++)
            {
                fileInput >> num1 >> num2;

                bool_val1 = num1[1] == '1' ? true : false;
                bool_val2 = num2[0] == '0' ? false : true;

                coppie[i] = new Coppia<bool>(bool_val1, bool_val2);
            }

            MaxHeap<bool> *bool_heap = new MaxHeap<bool>(coppie, dim);

            bool_heap->build_heap();
            bool_heap->sort();

            fileOutput << bool_heap->getHeapifyCount() << " ";
            fileOutput << bool_heap->print();

            // bool_heap->print();
        }
    }
}