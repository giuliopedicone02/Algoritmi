#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "moltiplicationChainedHashTable.h"

string print(int *arr, int dim)
{
    stringstream s;
    s.str("");

    for (int i = 0; i < dim; i++)
    {
        s << arr[i] << " ";
    }

    s << endl;

    return s.str();
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

    string type = "";
    int m = 0; // Numero di bucket della tabella hash
    int n = 0;

    int int_value = 0;
    double double_value = 0.0;
    char char_value = '\0';
    bool bool_value = false;

    while (fileInput.good())
    {
        fileInput >> type >> m >> n;

        if (type == "int")
        {
            MultiplicationChainedHashTable<int> *hashTable_int = new MultiplicationChainedHashTable<int>(m);

            for (int i = 0; i < n; i++)
            {
                fileInput >> int_value;
                hashTable_int->insertKey(int_value);
            }

            int *result = hashTable_int->chiaviPerLivello();
            fileOutput << print(result, m);
        }

        if (type == "double")
        {
            MultiplicationChainedHashTable<double> *hashTable_double = new MultiplicationChainedHashTable<double>(m);

            for (int i = 0; i < n; i++)
            {
                fileInput >> double_value;
                hashTable_double->insertKey(double_value);
            }

            int *result = hashTable_double->chiaviPerLivello();
            fileOutput << print(result, m);
        }

        if (type == "char")
        {
            MultiplicationChainedHashTable<char> *hashTable_char = new MultiplicationChainedHashTable<char>(m);

            for (int i = 0; i < n; i++)
            {
                fileInput >> char_value;
                hashTable_char->insertKey(char_value);
            }

            int *result = hashTable_char->chiaviPerLivello();
            fileOutput << print(result, m);
        }

        if (type == "bool")
        {
            MultiplicationChainedHashTable<bool> *hashTable_bool = new MultiplicationChainedHashTable<bool>(m);

            for (int i = 0; i < n; i++)
            {
                fileInput >> bool_value;
                hashTable_bool->insertKey(bool_value);
            }

            int *result = hashTable_bool->chiaviPerLivello();
            fileOutput << print(result, m);
        }
    }
}