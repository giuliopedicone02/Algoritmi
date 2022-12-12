#include <iostream>
#include <fstream>
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

int getPianficazioneMigliore(int cifra, int *giorno, int *inizio, int *fine, int *tassa, int *vincita, int dim)
{
    int saldo = cifra;
    int max = cifra;
    int lastGiorno = 0, lastInizio = 0, lastFine = 0;

    for (int i = 0; i < dim; i++)
    {
        saldo = cifra;

        if (verificaFondi(saldo, tassa[i])) // Ho abbastanza soldi per giocare
        {
            saldo = saldo + (vincita[i] - tassa[i]); // aggiorno il saldo

            /* CALCOLO DELLA CONFIGURAZIONE OTTIMALE*/

            lastGiorno = giorno[i];
            lastInizio = inizio[i];
            lastFine = fine[i];

            for (int j = 0; j < dim; j++)
            {
                // Se gli orari delle due partite (i != j) sono compatibili....
                if (i != j && verificaOrari(lastGiorno, lastInizio, lastFine, giorno[j], inizio[j], fine[j]))
                {
                    saldo = saldo + (vincita[j] - tassa[j]); // Aggiorno il saldo

                    lastGiorno = giorno[j];
                    lastInizio = inizio[j];
                    lastFine = fine[j];
                }
            }
        }

        // cout << "Saldo al ciclo " << i << ": " << saldo << " - guadagno: " << (vincita[i] - tassa[i]) << endl;

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

        int giorno[numero_partite]{0}, inizio[numero_partite]{0}, fine[numero_partite]{0};
        int tassa[numero_partite]{0}, vincita[numero_partite]{0};

        for (int i = 0; i < numero_partite; i++)
        {
            fileInput >> giorno[i] >> inizio[i] >> fine[i] >> tassa[i] >> vincita[i];
        }

        /*for (int i = 0; i < numero_partite; i++)
        {
            cout << giorno[i] << " " << inizio[i] << " " << fine[i] << " " << tassa[i] << " " << vincita[i] << endl;
        }*/

        // cout << getPianficazioneMigliore(cifra_a_disposizione, giorno, inizio, fine, tassa, vincita, numero_partite) << endl;

        fileOutput << getPianficazioneMigliore(cifra_a_disposizione, giorno, inizio, fine, tassa, vincita, numero_partite) << endl;
    }
}