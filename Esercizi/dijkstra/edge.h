#ifndef EDGE_H
#define EDGE_H
template <typename T>
class Edge
{
private:
    int sorgente, destinazione, peso;

    template <typename U>
    friend class Graph;

public:
    Edge(T sorgente, T destinazione, T peso) : sorgente(sorgente), destinazione(destinazione), peso(peso){};

    int getSorgente() { return sorgente; };
    int getDestinazione() { return destinazione; };
    int getPeso() { return peso; };
};
#endif