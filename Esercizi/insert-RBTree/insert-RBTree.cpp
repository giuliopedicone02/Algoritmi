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
    string visit = "";
    string str = "";
    int n = 0; // Numero di elementi da inserire o cancllare dal RBTree

    int int_value = 0;
    double double_value = 0.0;
    char char_value = '\0';
    bool bool_value = false;

    while (fileInput.good())
    {
        fileInput >> type >> n >> visit;

        if (type == "int")
        {
            RBTree<int> *RBTree_int = new RBTree<int>;

            for (int i = 0; i < n; i++)
            {
                fileInput >> int_value;

                RBTree_int->insertKey(int_value);
            }

            if (visit == "inorder")
            {
                RBTree_int->inorder();
            }

            if (visit == "preorder")
            {
                RBTree_int->preorder();
            }

            if (visit == "postorder")
            {
                RBTree_int->postorder();
            }

            fileOutput << RBTree_int->print() << endl;
        }

        if (type == "double")
        {
            RBTree<double> *RBTree_double = new RBTree<double>;

            for (int i = 0; i < n; i++)
            {
                fileInput >> double_value;

                RBTree_double->insertKey(double_value);
            }

            if (visit == "inorder")
            {
                RBTree_double->inorder();
            }

            if (visit == "preorder")
            {
                RBTree_double->preorder();
            }

            if (visit == "postorder")
            {
                RBTree_double->postorder();
            }

            fileOutput << RBTree_double->print() << endl;
        }

        if (type == "char")
        {
            RBTree<char> *RBTree_char = new RBTree<char>;

            for (int i = 0; i < n; i++)
            {
                fileInput >> char_value;

                RBTree_char->insertKey(char_value);
            }

            if (visit == "inorder")
            {
                RBTree_char->inorder();
            }

            if (visit == "preorder")
            {
                RBTree_char->preorder();
            }

            if (visit == "postorder")
            {
                RBTree_char->postorder();
            }

            fileOutput << RBTree_char->print() << endl;
        }

        if (type == "bool")
        {
            RBTree<bool> *RBTree_bool = new RBTree<bool>;

            for (int i = 0; i < n; i++)
            {
                fileInput >> bool_value;

                RBTree_bool->insertKey(bool_value);
            }

            if (visit == "inorder")
            {
                RBTree_bool->inorder();
            }

            if (visit == "preorder")
            {
                RBTree_bool->preorder();
            }

            if (visit == "postorder")
            {
                RBTree_bool->postorder();
            }

            fileOutput << RBTree_bool->print() << endl;
        }
    }
}