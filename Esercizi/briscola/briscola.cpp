#include <iostream>
#include <fstream>
#include "partita.h"
using namespace std;

bool verificaOrari(int giorno1, int inizio1, int fine1, int giorno2, int inizio2, int fine2)
{
    if (giorno1 != giorno2) // La partita si gioca in giorni diversi, ok!
    {
        return true;
    }

    if (fine1 < inizio2) // L'orario di fine della prima partita è inferiore all'orario di inizio della seconda, ok!
    {
        return true;
    }

    return false;
}

bool verificaFondi(int saldo, int tassa)
{
    if (tassa > saldo)
    {
        return false;
    }

    return true;
}

int getPianificazioneMigliore(int cifra, Partita **partita, int dim)
{
    int guadagno = 0;
    int saldo = cifra;
    int max = cifra;
    int lastGiorno = 0, lastInizio = 0, lastFine = 0;

    for (int i = 0; i < dim; i++)
    {
        saldo = cifra;

        if (partita[i]->verificaFondi(saldo)) // Ho abbastanza soldi per giocare
        {
            guadagno = partita[i]->getGuadagno(); // Guadagno della partita attuale

            /* CALCOLO DELLA CONFIGURAZIONE OTTIMALE*/

            Partita lastPartita = *partita[i];

            for (int j = 0; j < dim; j++)
            {
                // Se gli orari delle due partite (i != j) sono compatibili....
                if (i != j && verificaOrari(lastPartita, *partita[j]))
                {
                    guadagno += partita[j]->getGuadagno(); // Aggiorno guadagno ogni volta che posso giocare una partita
                    // cout << "Guadagno: " << guadagno << endl;
                    //  Aggiorno i dati con l'ultima partita giocata per il confronto successivo

                    lastPartita = *partita[j];
                }
            }
        }

        saldo += guadagno; // Aggiorno il saldo

        // cout << "Saldo al ciclo " << i << ": " << saldo << " - guadagno: " << partita[i]->getGuadagno() << endl;

        if (saldo > max)
        {
            max = saldo;
        }
    }

    return max;
}

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    int numero_partite = 0, cifra_a_disposizione = 0;

    for (int x = 0; x < 3; x++)
    {
        fileInput >> numero_partite >> cifra_a_disposizione;

        Partita **partite = new Partita *[numero_partite];

        int giorno = 0, inizio = 0, fine = 0;
        int tassa = 0, vincita = 0;

        for (int i = 0; i < numero_partite; i++)
        {
            fileInput >> giorno >> inizio >> fine >> tassa >> vincita;
            partite[i] = new Partita(giorno, inizio, fine, tassa, vincita);
        }

        // Stampa le partite

        /*for (int i = 0; i < numero_partite; i++)
        {
            cout << *partite[i];
        }*/

        // cout << getPianficazioneMigliore(cifra_a_disposizione, giorno, inizio, fine, tassa, vincita, numero_partite) << endl;

        fileOutput << getPianificazioneMigliore(cifra_a_disposizione, partite, numero_partite) << endl;
    }
}