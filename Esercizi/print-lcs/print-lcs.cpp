#include <iostream>
#include <fstream>
using namespace std;

/**
 * Nota Bene: Se il vostro PC genera meno di 100 elementi eseguire il codice con https://www.online-cpp.com/
 */

string lcs(string X, string Y, int m, int n)
{
    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    int index = L[m][n];

    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;

    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }

        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    return lcs;
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
    }
}
