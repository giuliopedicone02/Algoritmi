#include <iostream>
#include <fstream>
using namespace std;

int count(int *vett, int n, int r)
{
    int table[r + 1];

    table[0] = 0;

    for (int i = 1; i < r + 1; i++)
        table[i] = INT_MAX;

    for (int i = 1; i < r + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vett[j] <= i)
            {
                int sub_res = table[i - vett[j]];
                if (sub_res != INT_MAX && sub_res + 1 < table[i])
                    table[i] = sub_res + 1;
            }
        }
    }

    return table[r];
}

int main()
{
    int r = 0, n = 0, value = 0;
    int *coins;

    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
        return 0;
    }

    for (int x = 0; x < 100; x++)
    {
        fileInput >> r >> n;
        coins = new int[n];
        for (int i = 0; i < n; i++)
        {
            fileInput >> coins[i];
        }

        fileOutput << count(coins, n, r) << endl;
    }
}
