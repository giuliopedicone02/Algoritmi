#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "BST.h"

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
    string visit = "";
    string str = "";
    int m = 0; // Numero di operazioni di rotazione
    int n = 0; // Numero di elementi da inserire o cancllare dal BST

    int int_value = 0;
    double double_value = 0.0;

    for (int x = 0; x < 100; x++)
    {
        fileInput >> type >> n >> m >> visit;

        if (type == "int")
        {
            BST<int> *BST_int = new BST<int>;

            for (int i = 0; i < n; i++)
            {
                fileInput >> str;

                if (str[0] == 'i') // Inserimento
                {
                    int_value = stoi(str.substr(4, str.length()));
                    BST_int->insert(int_value);
                }
                else if (str[0] == 'c') // Cancellazione
                {
                    int_value = stoi(str.substr(5, str.length()));
                    BST_int->remove(int_value);
                }
            }

            for (int i = 0; i < m; i++)
            {
                fileInput >> str;

                if (str[0] == 'l') // Rotazione a sinistra
                {
                    int_value = stoi(str.substr(5, str.length()));
                    BST_int->leftRotate(int_value);
                }
                else if (str[0] == 'r') // Rotazione a destra
                {
                    int_value = stoi(str.substr(6, str.length()));
                    BST_int->rightRotate(int_value);
                }
            }

            if (visit == "inorder")
            {
                BST_int->inorder();
            }

            if (visit == "preorder")
            {
                BST_int->preorder();
            }

            if (visit == "postorder")
            {
                BST_int->postorder();
            }

            fileOutput << BST_int->print() << endl;
        }

        if (type == "double")
        {
            BST<double> *BST_double = new BST<double>;

            for (int i = 0; i < n; i++)
            {
                fileInput >> str;

                if (str[0] == 'i') // Inserimento
                {
                    double_value = stod(str.substr(4, str.length()));
                    BST_double->insert(double_value);
                }
                else if (str[0] == 'c') // Cancellazione
                {
                    double_value = stod(str.substr(5, str.length()));
                    BST_double->remove(double_value);
                }
            }

            for (int i = 0; i < m; i++)
            {
                fileInput >> str;

                if (str[0] == 'l') // Rotazione a sinistra
                {
                    double_value = stod(str.substr(5, str.length()));
                    BST_double->leftRotate(double_value);
                }
                else if (str[0] == 'r') // Rotazione a destra
                {
                    double_value = stod(str.substr(6, str.length()));
                    BST_double->rightRotate(double_value);
                }
            }

            if (visit == "inorder")
            {
                BST_double->inorder();
            }

            if (visit == "preorder")
            {
                BST_double->preorder();
            }

            if (visit == "postorder")
            {
                BST_double->postorder();
            }

            fileOutput << BST_double->print() << endl;
        }
    }
}