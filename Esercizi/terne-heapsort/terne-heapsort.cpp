#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "terne.h"
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

    int dim = 0, int_val1 = 0, int_val2 = 0, int_val3 = 0;
    double double_val1 = 0.0, double_val2 = 0.0, double_val3 = 0;
    char char_val1 = '\0', char_val2 = '\0', char_val3 = '\0';
    bool bool_val1 = false, bool_val2 = false, bool_val3 = false;
    string type = "";
    string num1 = " ", num2 = " ", num3 = " ";
    char parentesi = '\0';

    for (int x = 0; x < 100; x++)
    {
        fileInput >> type >> dim;

        if (type == "int")
        {
            Terne<int> **coppie = new Terne<int> *[dim];

            for (int i = 0; i < dim; i++)
            {
                fileInput >> parentesi >> num1 >> num2 >> num3;

                int_val1 = stoi(num1);
                int_val2 = stoi(num2);
                int_val3 = stoi(num3);

                coppie[i] = new Terne<int>(int_val1, int_val2, int_val3);
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
            Terne<double> **coppie = new Terne<double> *[dim];

            for (int i = 0; i < dim; i++)
            {
                fileInput >> parentesi >> num1 >> num2 >> num3;

                double_val1 = stod(num1);
                double_val2 = stod(num2);
                double_val3 = stod(num3);

                coppie[i] = new Terne<double>(double_val1, double_val2, double_val3);
            }
            MaxHeap<double> *double_heap = new MaxHeap<double>(coppie, dim);

            double_heap->build_heap();
            double_heap->sort();

            fileOutput << double_heap->getHeapifyCount() << " ";
            fileOutput << double_heap->print();
        }

        if (type == "char")
        {
            Terne<char> **coppie = new Terne<char> *[dim];

            for (int i = 0; i < dim; i++)
            {
                fileInput >> parentesi >> char_val1 >> char_val2 >> char_val3 >> parentesi;

                coppie[i] = new Terne<char>(char_val1, char_val2, char_val3);
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
            Terne<bool> **coppie = new Terne<bool> *[dim];

            for (int i = 0; i < dim; i++)
            {
                fileInput >> num1 >> num2 >> num3;

                bool_val1 = num1[1] == '1' ? true : false;
                bool_val2 = num2[0] == '0' ? false : true;
                bool_val3 = num3[0] == '1' ? true : false;

                coppie[i] = new Terne<bool>(bool_val1, bool_val2, bool_val3);
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