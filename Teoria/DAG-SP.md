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

**Ordinamento topologico di un grafo:**

I nodi di un grafo si definiscono ordinati topologicamente se i nodi sono disposti in modo tale che ogni nodo viene prima di tutti i nodi collegati ai suoi archi uscenti.

∃ arco tra v ed u => u<v

**Vincoli di utilizzo:** Il grafo non deve possedere cicli