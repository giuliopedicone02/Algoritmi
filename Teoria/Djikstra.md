# Djikstra

<p align="center">
  <img src="https://i.ytimg.com/vi/pVfj6mxhdMw/hqdefault.jpg">
</p>


**Complessità:** O((V+E) log V) oppure O(V^2*log(V))

```c++
function relax(u,v,w) //Abbassa la stima di cammino minimo
{
    if(d[v]>d[u]+w(u,v))
    {
        d[v]=d[u]+w[u,v];
        previous[v]=u;
    }
}

function dijkstra(G, S)
    for each vertex V in G
        distance[V] <- infinite
        previous[V] <- NULL
    distance[S] <- 0
	
    Q=V //Coda con priorità: min heap

    while Q IS NOT EMPTY
        U <- Extract MIN from Q
        for each unvisited neighbour V of U
            relax(u,v,w)
```

**Vincoli di utilizzo:** Il grafo non deve possedere archi di peso negativo