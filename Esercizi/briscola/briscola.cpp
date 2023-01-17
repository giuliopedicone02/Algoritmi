#include <iostream>
#include <fstream>
#include "partita.h"
using namespace std;

int getPianificazioneMigliore(int cifra, Partita **partita, int dim)
{
    int guadagno = 0;
    int max = cifra;

    for (int i = 0; i < dim; i++)
    {
        /*if (partita[i]->verificaFondi(saldo)) // Ho abbastanza soldi per giocare
        {*/
        guadagno = partita[i]->getGuadagno(); // Guadagno della partita attuale

        /* CALCOLO DELLA CONFIGURAZIONE OTTIMALE*/

        Partita lastPartita = *partita[i];

        for (int j = 0; j < dim; j++)
        {
            // Se gli orari delle due partite (i != j) sono compatibili....
            if (i != j && verificaOrari(lastPartita, *partita[j]))
            {
                guadagno += partita[j]->getGuadagno(); // Aggiorno guadagno ogni volta che posso giocare una partita

                // Aggiorno i dati con l'ultima partita giocata per il confronto successivo
                lastPartita = *partita[j];
            }
        }
        /*}*/

        guadagno += cifra; // Aggiorno il guadagno aggiungendo la cifra a disposizione

        if (guadagno > max)
        {
            max = guadagno;
        }
    }

    return max;
}

int main()
{
    fstream fileInput("input2.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    int numero_partite = 0, cifra_a_disposizione = 0;

    for (int x = 0; x < 5; x++)
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

        getPartiteGiocabili(partite, numero_partite, cifra_a_disposizione);

        if (numero_partite == 0)
        {
            fileOutput << cifra_a_disposizione << endl;
        }
        else
        {
            sort(partite, numero_partite);

            // Stampa le partite

            for (int i = 0; i < numero_partite; i++)
            {
                cout << *partite[i];
            }

            cout << endl
                 << endl;

            fileOutput << getPianificazioneMigliore(cifra_a_disposizione, partite, numero_partite) << endl;
        }
    }
}