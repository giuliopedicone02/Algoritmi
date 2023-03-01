# Directed Acyclic Graph Shortest Path

<p align="center">
  <img src="https://media.geeksforgeeks.org/wp-content/uploads/shortestpathstart.jpg">
</p>


**Complessità:** O(V+E) oppure O(V^2)

```c++

function relax(u,v,w) //Abbassa la stima di cammino minimo
{
    if(d[v]>d[u]+w(u,v))
    {
        d[v]=d[u]+w[u,v];
        previous[v]=u;
    }
}

function DAG-SP(G, S, w)
{
  sia π un ordinamento topologico
  
  for i=0 to n-1 
    v=π[i]
    for each u ∈ adj[v]
        relax(u,v,w)
}
```

**Vincoli di utilizzo:** Il grafo non deve possedere cicli

**Ordinamento topologico di un grafo:**

I nodi di un grafo si definiscono ordinati topologicamente se i nodi sono disposti in modo tale che ogni nodo viene prima di tutti i nodi collegati ai suoi archi uscenti.

∃ arco tra v ed u tale che u<v

**DFS (Depth First Search):**


<p align="center">
  <img src="https://www.researchgate.net/publication/334027256/figure/fig2/AS:773861096296448@1561514271440/Depth-First-Search-progress-251-Depth-First-Search-Algorithm-1-If-the-initial-state-is.ppm">
</p>

**Complessità:** O(V+E) oppure O(V^2)

Ricerca in profondità all'interno di un grafo che permette di creare un ordinamento topologico.

I nodi sono di tre colori:
* Bianco: Nodo da visitare
* Grigio: Visita iniziata
* Nero: Visita terminata

```c++
DFS(G)
{ 
  for each v ∈ V 
    color(v)= WHITE
    π[v] = NULL

  for each v ∈ V
      if color(v) == WHITE
        DFS-VISIT(v)
}

DFS-VISIT(v)
{ 
  color(v) = GRAY

  for each u ∈ adj[v] 
    if color(u) == WHITE
      DFS-VISIT(u)
      π[u] = v

  color(v) = BLACK
}
```
