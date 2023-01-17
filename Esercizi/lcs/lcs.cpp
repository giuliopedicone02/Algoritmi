#include <iostream>
#include <fstream>
using namespace std;

/**
 * Nota Bene: Se il vostro PC genera meno di 100 elementi eseguire il codice con https://www.online-cpp.com/
 */

int lcs(string X, string Y, int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    return L[m][n];
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n = 0, m = 0;
    string str1 = "", str2 = "";

    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
        return 0;
    }

    for (int x = 0; x < 100; x++)
    {
        fileInput >> n >> m >> str1 >> str2;
        fileOutput << lcs(str1, str2, n, m) << endl;
        cout << "Ok #" << x << endl;
    }
}