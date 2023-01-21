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
    friend int getPianificazioneMigliore(int, Partita *, int);

    ostream &put(ostream &os)
    {
        os << giorno << " " << inizio << " " << fine << " " << tassa << " " << vincita << endl;
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

    if (p1.fine < p2.inizio) // L'orario di fine della prima partita è inferiore all'orario di inizio della seconda, ok!
    {
        return true;
    }

    return false;
}

#endif