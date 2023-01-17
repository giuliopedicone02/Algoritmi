#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"
#include <iostream>
#include <climits>
#include <fstream>
using namespace std;

template <typename T>
class Graph
{
private:
    Edge<T> **edges;
    T *nodes;

    int size_nodes, size_edges, current_nodes, current_edges;

    int search(T elem)
    {
        int k = 0;
        while (k < current_nodes && nodes[k] != elem)
            k++;
        if (k == current_nodes)
            return -1;
        return k;
    }

    int get_min(int *vett)
    {
        int min = -1;
        for (int i = 1; i < current_nodes; i++)
        {
            if (vett[i] < vett[i - 1])
                min = i;
        }
        if (min < 0)
            return -1;
        return min;
    }

public:
    Graph(int size_nodes)
    {
        this->size_nodes = size_nodes;
        size_edges = size_nodes * size_nodes;
        current_nodes = current_edges = 0;
        nodes = new T[this->size_nodes];
        edges = new Edge<T> *[this->size_edges];
    }

    Graph *insert_node(T elem)
    {
        if (current_nodes < size_nodes)
        {
            nodes[current_nodes] = elem;
            current_nodes++;
        }
        return this;
    }

    Graph *insert_edge(T a, T b, int cost)
    {
        if (current_edges < size_edges)
        {
            int index_a = search(a);
            int index_b = search(b);
            if (index_a < 0 || index_b < 0)
                return this;
            edges[current_edges] = new Edge<T>(index_a, index_b, cost);
            current_edges++;
        }
        return this;
    }

    string dijkstra(T source, T destination)
    {
        string result = "inf";
        int *pred = new int[size_nodes];
        int start = search(source);
        int end = search(destination);

        if (start < 0 || end < 0)
            return " ";

        int *costs = new int[size_nodes];

        for (int i = 0; i < size_nodes; i++)
        {
            costs[i] = INT_MAX;
            pred[i] = INT_MAX;
        }

        costs[start] = 0;
        pred[start] = -1;
        int tmp;

        for (int i = 0; i < size_nodes; i++)
        {
            int tmp = get_min(costs);
            for (int k = 0; k < current_edges; k++)
            {
                if (costs[edges[k]->sorgente] != INT_MAX && costs[edges[k]->sorgente] + edges[k]->peso < costs[edges[k]->destinazione])
                {
                    pred[edges[k]->destinazione] = tmp;
                    costs[edges[k]->destinazione] = costs[edges[k]->sorgente] + edges[k]->peso;
                }
            }
        }

        if (costs[end] != INT_MAX)
            result = to_string(costs[end]);

        delete[] costs;
        delete[] pred;
        return result;
    }
};
#endif
