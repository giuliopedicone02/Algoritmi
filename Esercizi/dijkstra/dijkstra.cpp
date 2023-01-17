#include <iostream>
using namespace std;

#include "graph.h"

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
        return 0;
    }

    int V = 0, E = 0;
    int int_value = 0, source_int = 0, destination_int = 0, weight_int = 0, inizio_int = 0, fine_int = 0;
    double double_value = 0.0, source_double = 0.0, destination_double = 0.0, weight_double = 0.0, double_inizio = 0.0, double_fine = 0.0;
    string type = "", sorgente, destinazione, peso;
    char parentesi = '\0';

    for (int x = 0; x < 100; x++)
    {
        fileInput >> V >> E >> type;

        if (type == "int")
        {
            Graph<int> *grafoInt = new Graph<int>(V);

            for (int i = 0; i < V; i++)
            {
                fileInput >> int_value;
                grafoInt->insert_node(int_value);
            }

            for (int i = 0; i < E; i++)
            {
                fileInput >> sorgente >> destinazione >> peso;

                sorgente = sorgente.substr(1, sorgente.length()); // Elimina la parentesi (
                peso = peso.substr(0, peso.length() - 1);         // Elimina la parentesi )

                source_int = stoi(sorgente);
                destination_int = stoi(destinazione);
                weight_int = stoi(peso);

                // cout << "source: " << source_int << ", destination: " << destination_int << ", weight: " << weight_int << endl;

                grafoInt->insert_edge(source_int, destination_int, weight_int);
            }

            fileInput >> inizio_int >> fine_int;

            fileOutput << grafoInt->dijkstra(inizio_int, fine_int) << endl;
        }

        if (type == "double")
        {
            Graph<double> *grafoDouble = new Graph<double>(V);

            for (int i = 0; i < V; i++)
            {
                fileInput >> double_value;
                grafoDouble->insert_node(double_value);
            }

            for (int i = 0; i < E; i++)
            {
                fileInput >> sorgente >> destinazione >> peso;
                sorgente = sorgente.substr(1, sorgente.length()); // Elimina la parentesi (
                peso = peso.substr(0, peso.length() - 1);         // Elimina la parentesi )

                source_double = stod(sorgente);
                destination_double = stod(destinazione);
                weight_double = stod(peso);

                // cout << "source: " << source_double << ", destination: " << destination_double << ", weight: " << weight_double << endl;

                grafoDouble->insert_edge(source_double, destination_double, weight_double);
            }

            fileInput >> sorgente >> destinazione;

            double_inizio = stod(sorgente);
            double_fine = stod(destinazione);

            fileOutput << grafoDouble->dijkstra(double_inizio, double_fine) << endl;
        }
    }
}