/**
 * ATTENZIONE: QUESTO ESERCIZIO NON PRODUCE UN OUTPUT CORRETTO AL 100%
 */

#include <iostream>
#include <fstream>
#include "partita.h"
using namespace std;

int getPianificazioneMigliore(int cifra, Partita **partita, int dim)
{
    int guadagno[dim];
    guadagno[0] = partita[0]->getGuadagno();

    for (int i = 1; i < dim; i++)
    {
        int aux = partita[i]->getGuadagno();
        int last = ultimaPartita(partita, i);

        if (last != -1)
        {
            aux += guadagno[last];
        }

        if (aux > guadagno[i - 1])
        {
            guadagno[i] = aux;
        }
        else
        {
            guadagno[i] = guadagno[i - 1];
        }
    }

    return guadagno[dim - 1] + cifra;
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

    for (int x = 0; x < 100; x++)
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

            fileOutput << getPianificazioneMigliore(cifra_a_disposizione, partite, numero_partite) << endl;
        }
    }
}