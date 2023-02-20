# Bellman Ford

<p align="center">
  <img src="https://www.simplilearn.com/ice9/free_resources_article_thumb/Bellman%20Ford%20Algorithm/what-is-bellman-ford-algorithm.png">
</p>


**Complessità:** O(V*E) oppure O(V^3)

```c++

function relax(u,v,w) //Abbassa la stima di cammino minimo
{
    if(d[v]>d[u]+w(u,v))
    {
        d[v]=d[u]+w[u,v];
        previous[v]=u;
    }
}

function bellmanFord(G, S, w)
{
  for each vertex V in G
    distance[V] <- infinite
    previous[V] <- NULL
  
  distance[S] <- 0

  for each vertex V in G				
    for each edge (U,V) in G
        relax(u,v,w)

  for each edge (U,V) in G
    If distance[U] + edge_weight(U, V) < distance[V]
      Error: Negative Cycle Exists
}

function print_shortest_path(v,pred)
{
    stack = NULL;

    while(v!=NULL) DO
        push(stack,v)
        v=pred[v]
    
    while(stack!=NULL)
        v=pop(stack)
        print(v)
}

function recursive_print_shortest_path(v,pred)
{
    if(pred[v]==NULL)
    {
        print(v)
        return;
    }

    recursive_print_shortest_path(pred[v],pred)
    print(v)
}

**Vincoli di utilizzo:** Il grafo non deve possedere cicli di peso negativo

```