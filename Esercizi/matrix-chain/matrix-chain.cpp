#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int MatrixChainMultiplication(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0; // number of multiplications are 0(zero) when there is only one matrix

    // Here L is chain length. It varies from length 2 to length n.
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX; // assigning to maximum value

            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q; // if number of multiplications found less that number will be updated.
                }
            }
        }
    }

    return m[1][n - 1]; // returning the final answer which is M[1][n]
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

    int dim = 0, int_val = 0;
    string type = "";
    string num = " ";

    for (int x = 0; x < 100; x++)
    {
        fileInput >> dim;

        int arr[dim + 1];

        fileInput >> num;

        arr[0] = stoi(num.substr(1, num.find('x')));
        arr[1] = stoi(num.substr(num.find('x') + 1, num.length() - 1));

        for (int i = 2; i < dim + 1; i++)
        {
            fileInput >> num;
            arr[i] = stoi(num.substr(num.find('x') + 1, num.length() - 1));
        }

        fileOutput << MatrixChainMultiplication(arr, dim + 1) << endl;
    }
}