#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    int *val;
    int N = 0, W = 0, p = 0, s = 0;

    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
        return 0;
    }

    for (int x = 0; x < 100; x++)
    {
        fileInput >> N >> W;

        val = new int[N];
        s = 0;

        for (int i = 0; i < N; i++)
        {
            fileInput >> val[i];
        }

        sort(val, val + N, greater<int>()); // Ordinamento ascendente

        for (int i = 0; i < W; i++)
        {
            s += val[i];
        }

        fileOutput << s << endl;

        delete[] val;
    }

    return 0;
}
