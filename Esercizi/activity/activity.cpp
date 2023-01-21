#include <iostream>
#include <fstream>

#include "activity.h"
using namespace std;

int lastactivity(Activity **A, int i)
{
    int k = i;
    for (int j = i - 1; j >= 0; j--)
    {
        if (A[j]->fine <= A[k]->inizio)
            return j;
    }
    return -1;
}

int getTempoMassimo(Activity **eventi, int n)
{
    int arr[n];
    arr[0] = eventi[0]->getTempo();

    for (int i = 1; i < n; i++)
    {
        int sum = eventi[i]->getTempo();
        int l = lastactivity(eventi, i);

        if (l != -1)
        {
            sum += arr[l];
        }

        if (sum > arr[i - 1])
        {
            arr[i] = sum;
        }

        else
        {
            arr[i] = arr[i - 1];
        }
    }

    return arr[n - 1];
}

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n = 0;
    string inizio = "", fine = "";
    int int_inizio = 0, int_fine = 0;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    for (int x = 0; x < 100; x++)
    {
        fileInput >> n;

        Activity **eventi = new Activity *[n];

        for (int i = 0; i < n; i++)
        {
            fileInput >> inizio >> fine;

            int_inizio = stoi(inizio.substr(1, inizio.length()));
            int_fine = stoi(fine.substr(0, fine.length() - 1));

            eventi[i] = new Activity(int_inizio, int_fine);

            // cout << *eventi[i];
        }

        sort(eventi, n);

        fileOutput << getTempoMassimo(eventi, n) << endl;
    }
}