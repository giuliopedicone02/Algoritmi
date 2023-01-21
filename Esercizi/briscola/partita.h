#ifndef PARTITA_H
#define PARTITA_H

#include <iostream>
using namespace std;

class Partita
{
private:
    int giorno;
    int inizio;
    int fine;
    int tassa;
    int vincita;

public:
    Partita(int giorno, int inizio, int fine, int tassa, int vincita) : giorno(giorno), inizio(inizio), fine(fine), tassa(tassa), vincita(vincita){};

    friend bool verificaOrari(Partita, Partita);
    friend int ultimaPartita(Partita **, int);
    friend int getPianificazioneMigliore(int, Partita **, int);
    friend void getPartiteGiocabili(Partita **&, int &, int);
    friend int *getNumeroPartiteGiornaliere(Partita **, int);
    friend void sort(Partita **, int dim);

    ostream &put(ostream &os)
    {
        os << giorno << " " << inizio << " " << fine << " " << tassa << " " << vincita << " - guadagno: " << getGuadagno() << endl;
        return os;
    }

    bool verificaFondi(int saldo)
    {
        if (tassa > saldo)
        {
            return false;
        }

        return true;
    }

    int getGuadagno()
    {
        return vincita - tassa;
    }

    friend bool operator<(Partita, Partita);
    friend bool operator>(Partita, Partita);
    friend bool operator==(Partita, Partita);
};

ostream &operator<<(ostream &os, Partita &obj)
{
    return obj.put(os);
}

bool verificaOrari(Partita p1, Partita p2)
{
    if (p1.giorno != p2.giorno) // La partita si gioca in giorni diversi, ok!
    {
        return true;
    }

    if (p1.giorno == p2.giorno && p1.fine <= p2.inizio) // L'orario di fine della prima partita è inferiore all'orario di inizio della seconda, ok!
    {
        return true;
    }

    return false;
}

int ultimaPartita(Partita **partita, int i)
{
    int k = i;
    for (int j = i - 1; j >= 0; j--)
    {
        if (verificaOrari(*partita[j], *partita[k]))
            return j;
    }
    return -1;
}

void getPartiteGiocabili(Partita **&partita, int &dim, int cifra)
{
    Partita *arr[dim];
    int cont = 0;

    for (int i = 0; i < dim; i++)
    {
        if (partita[i]->tassa <= cifra)
        {
            arr[cont] = partita[i];
            cont++;
        }
    }

    dim = cont;

    for (int i = 0; i < dim; i++)
    {
        partita[i] = arr[i];
    }
}

bool operator==(Partita p1, Partita p2)
{
    if (p1.giorno == p2.giorno)
    {
        if (p1.inizio == p2.inizio)
        {
            if (p1.fine == p2.fine)
            {
                return true;
            }
        }
    }

    return false;
}

bool operator<(Partita p1, Partita p2)
{
    if (p1.giorno < p2.giorno)
    {
        return true;
    }

    if (p1.inizio < p2.inizio)
    {
        return true;
    }

    return false;
}

bool operator>(Partita p1, Partita p2)
{

    if (p1.giorno > p2.giorno) // La partita p1 inizia un giorno successivo alla partita p2
    {
        return true;
    }
    else if (p1.giorno == p2.giorno)
    {
        if (p1.fine > p2.fine)
        {
            return true;
        }
    }

    return false;
}

void swap(Partita &a, Partita &b)
{
    Partita temp = a;
    a = b;
    b = temp;
}

void sort(Partita **partita, int dim)
{
    for (int c = 0; c < dim; c++)
    {
        for (int i = c + 1; i < dim; i++)
        {
            if (*partita[c] > *partita[i])
            {
                swap(*partita[c], *partita[i]);
            }
        }
    }
}

#endif