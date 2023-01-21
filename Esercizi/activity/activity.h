#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <iostream>
using namespace std;

class Activity
{
private:
    int inizio;
    int fine;

    friend void swap(Activity &, Activity &);
    friend void sort(Activity **, int dim);
    friend bool operator>(Activity, Activity);
    friend int getTempoMassimo(Activity **, int n);
    friend int lastactivity(Activity **A, int i);

public:
    Activity(int inizio, int fine) : inizio(inizio), fine(fine){};

    int getTempo() { return fine - inizio; };

    ostream &put(ostream &os)
    {
        os << "Inizio: " << inizio << ", fine: " << fine << " - tempo: " << getTempo() << endl;
        return os;
    }
};

ostream &operator<<(ostream &os, Activity &obj)
{
    return obj.put(os);
}

void swap(Activity &a, Activity &b)
{
    Activity temp = a;
    a = b;
    b = temp;
}

void sort(Activity **evento, int dim)
{
    for (int c = 0; c < dim; c++)
    {
        for (int i = c + 1; i < dim; i++)
        {
            if (*evento[c] > *evento[i])
            {
                swap(*evento[c], *evento[i]);
            }
        }
    }
}

bool operator>(Activity a1, Activity a2)
{
    if (a1.fine > a2.fine)
    {
        return true;
    }

    return false;
}

#endif