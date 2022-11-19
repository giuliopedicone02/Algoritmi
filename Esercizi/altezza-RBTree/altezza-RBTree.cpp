#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "RBTree.h"

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
    string str = "";
    int n = 0; // Numero di elementi da inserire o cancllare dal RBTree

    int int_value = 0;
    double double_value = 0.0;

    while (fileInput.good())
    {
        fileInput >> type >> n;

        if (type == "int")
        {
            RBTree<int> *RBTree_int = new RBTree<int>;

            for (int i = 0; i < n; i++)
            {
                fileInput >> int_value;

                RBTree_int->insertKey(int_value);
            }

            fileOutput << RBTree_int->getTreeHeight() << endl;
        }

        if (type == "double")
        {
            RBTree<double> *RBTree_double = new RBTree<double>;

            for (int i = 0; i < n; i++)
            {
                fileInput >> double_value;

                RBTree_double->insertKey(double_value);
            }

            fileOutput << RBTree_double->getTreeHeight() << endl;
        }
    }
}