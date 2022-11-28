#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

template <typename T>
void print(T *arr, int dim, fstream &out)
{
    for (int i = 0; i < dim; i++)
    {
        out << arr[i] << " ";
    }
}

class Coppia
{
private:
    double x;
    double y;

public:
    Coppia(double x, double y) : x(x), y(y){};

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    bool operator<(Coppia c)
    {
        if (this->x < c.x)
        {
            return true;
        }

        if (this->x == c.x && this->y < c.y)
        {
            return true;
        }

        if (this->x == c.x && this->y == c.y)
        {
            return false;
        }

        return false;
    }
    bool operator>(Coppia c)
    {
        if (this->x > c.x)
        {
            return true;
        }

        if (this->x == c.x && this->y > c.y)
        {
            return true;
        }

        if (this->x == c.x && this->y == c.y)
        {
            return false;
        }

        return false;
    }
    bool operator<=(Coppia c)
    {
        if (this->x < c.x)
        {
            return true;
        }

        if (this->x == c.x && this->y < c.y)
        {
            return true;
        }

        if (this->x == c.x && this->y == c.y)
        {
            return true;
        }

        return false;
    }
    bool operator>=(Coppia c)
    {
        if (this->x > c.x)
        {
            return true;
        }

        if (this->x == c.x && this->y > c.y)
        {
            return true;
        }

        if (this->x == c.x && this->y == c.y)
        {
            return true;
        }

        return false;
    }

    bool operator==(Coppia c)
    {
        if (this->x == c.x && this->y == c.y)
        {
            return true;
        }

        return false;
    }

    friend int findMin(Coppia **, int);
    friend int findMax(Coppia **, int);

    friend ostream &operator<<(ostream &output, Coppia &coppia)
    {
        return output << "(" << coppia.x / 10 << " " << coppia.y / 10 << ")";
    }
};

int findMin(Coppia **arr, int dim)
{
    int min = arr[0]->getX();
    for (int i = 0; i < dim; i++)
    {
        if (arr[i]->getX() < min)
        {
            min = arr[i]->getX();
        }
    }

    return min;
}

int findMax(Coppia **arr, int dim)
{
    int max = arr[0]->getX();
    for (int i = 0; i < dim; i++)
    {
        if (arr[i]->getX() > max)
        {
            max = arr[i]->getX();
        }
    }

    return max;
}

void countingSort(Coppia **array, int size, fstream &out)
{
    int min = findMin(array, size);
    int max = findMax(array, size);

    int range = max - min + 1;

    Coppia **tmp = new Coppia *[size];
    int *freq = new int[range];

    for (int i = 0; i < range; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        freq[array[i]->getX() - min]++;
    }

    for (int i = 1; i < range; i++)
    {
        freq[i] += freq[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        tmp[freq[array[i]->getX() - min] - 1] = array[i];
        freq[array[i]->getX() - min]--;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = tmp[i];
    }

    print(freq, range, out);
    delete[] freq;
    delete[] tmp;
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

    int dim = 0;
    string value = "", num1 = "", num2 = "";
    double val1 = 0.0, val2 = 0.0;
    for (int x = 0; x < 100; x++)
    {
        fileInput >> dim;

        Coppia **coppie = new Coppia *[dim];

        for (int i = 0; i < dim; i++)
        {
            fileInput >> num1 >> num2;

            num1 = num1.substr(1, num1.length());
            num2 = num2.substr(0, num2.length() - 1);

            val1 = stod(num1);
            val2 = stod(num2);

            val1 = val1 * 10;
            val2 = val2 * 10;

            coppie[i] = new Coppia(val1, val2);
        }

        countingSort(coppie, dim, fileOutput);

        for (int i = 0; i < dim; i++)
        {
            fileOutput << *coppie[i] << " ";
        }

        fileOutput << endl;
    }
}