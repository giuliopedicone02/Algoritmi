# All Pair Shortest Path (APSP)

In un Single Source Shortest Path otteniamo un array di cammini minimi

In un All Pair Shortest Path otteniamo una matrice di cammini minimi

Un'idea sarebbe quella di applicare gli algoritmi precedentemente studiati ottenendo le seguenti complessità:

* Bellman-Ford: O(V * V^3) = O(V^4)
* Dijkstra: O(V * V^2 log V) = O(V^3 log V)
* DAG-SP: O(V * V^2) = O(V^3)


## Floyd-Warshall

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/b/b2/Floyd-Warshall-Algorithm-Problem.png">
</p>


**Complessità:** O(V^3)

```c++
Floyd-Warshall(W)
{
  D(0)=W

  for k=1 to n 
    D(k) = new matrix(n*n)
    for i=1 to n
        for j=1 to n

            D(k)[i,j] = D(k-1)[i,j]

            if(D(k-1)[i,k] + D(k-1)[k,j] < D(k)[i,j])
                D(k)[i,j] = D(k-1)[i,k] + D(k-1)[k,j] 
                π(k)[i,j] = π(k)[k,j]

    return D(n)
}
```