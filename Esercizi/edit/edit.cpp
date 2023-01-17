#include <iostream>
#include <fstream>
using namespace std;

/**
 * Nota Bene: Se il vostro PC genera meno di 100 elementi eseguire il codice con https://www.online-cpp.com/
 */

int min(int x, int y, int z) { return min(min(x, y), z); }

int editDist(string str1, string str2, int m, int n)
{

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }

            else if (j == 0)
            {
                dp[i][j] = i;
            }

            else if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }

            else
            {
                dp[i][j] = 1 + min(dp[i][j - 1],
                                   dp[i - 1][j],
                                   dp[i - 1][j - 1]);
            }
        }
    }

    return dp[m][n];
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
        fileOutput << editDist(str1, str2, n, m) << endl;
    }
}