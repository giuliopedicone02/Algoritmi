#include <iostream>
#include <fstream>

#include "activity.h"
using namespace std;

int getActivity(Activity **eventi, int n)
{
    int count = 1;
    int ultimoEvento = eventi[0]->fine;

    for (int i = 1; i < n; i++)
    {
        if (eventi[i]->inizio >= ultimoEvento)
        {
            count++;
            ultimoEvento = eventi[i]->fine;
        }
    }

    return count;
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

        fileOutput << getActivity(eventi, n) << endl;
    }
}