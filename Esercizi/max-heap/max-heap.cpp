#include <iostream>
#include <fstream>
#include <typeinfo>
#include <cstring>
#include <sstream>

using namespace std;

template <class H>
class MaxHeap
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

    void max_heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int max = i;
        if (l <= heapsize && array[l] > array[max])
            max = l;
        if (r <= heapsize && array[r] > array[max])
            max = r;
        if (max != i)
        {
            swap(i, max);
            max_heapify(max);
        }
        if (heapsize >= 1)
            cont++;
    }

public:
    MaxHeap(int len)
    {
        array = new H[len + 1];
        size = len + 1;
        heapsize = 0;
        cont = 0;
        s.str("");
    }

    void enqueue(H elem)
    {
        heapsize++;
        array[heapsize] = elem;
        int i = heapsize;
        while (i > 1 && array[parent(i)] < array[i])
        {
            swap(parent(i), i);
            i = parent(i);
        }
    }

    void extract()
    {
        swap(1, heapsize);
        heapsize--;
        max_heapify(1);
    }

    int getHeapifyCount()
    {
        return cont;
    }

    string print()
    {
        for (int i = 1; i <= heapsize; i++)
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
            MaxHeap<int> *int_heap = new MaxHeap<int>(dim);

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

            fileOutput << int_heap->getHeapifyCount() << " ";
            fileOutput << int_heap->print();
        }

        if (type == "double")
        {
            MaxHeap<double> *double_heap = new MaxHeap<double>(dim);

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

            fileOutput << double_heap->getHeapifyCount() << " ";
            fileOutput << double_heap->print();
        }

        if (type == "char")
        {
            MaxHeap<char> *char_heap = new MaxHeap<char>(dim);

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

            fileOutput << char_heap->getHeapifyCount() << " ";
            fileOutput << char_heap->print();
        }

        if (type == "bool")
        {
            MaxHeap<bool> *bool_heap = new MaxHeap<bool>(dim);

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

            fileOutput << bool_heap->getHeapifyCount() << " ";

            fileOutput << bool_heap->print();
        }
    }
}