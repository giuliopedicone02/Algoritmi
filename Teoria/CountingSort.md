# Counting Sort

<p align="center">
  <img src="https://www.researchgate.net/publication/220686480/figure/fig4/AS:667707569614851@1536205298801/Example-of-counting-sort.png">
</p>

Gli algoritmi di ordinamento studiati finora, basati sul confronto hanno al massimo come complessità O(n log n)

Questo algoritmo utilizza 3 array:
* il primo array A sono i valori che diamo in input
* il secondo array B sarà l'array A ordinat
* il terzo array C conterrà il numero di volte che un singolo valore si presenta all'interno dell'array A

Nota bene: L'algoritmo Counting Sort non è un algoritmo stabile in quanto non utilizza direttamente gli elementi dell'array A ma li ricrea nell'array B

La complessità è uguale ad O(n+k) dove k è il range di numeri dell'array A, nell'esempio sopra è [1,7]

## Codice Counting Sort O(n+k)
```c++
template <typename T>
T *countingSort(T *array, int size)
{
    T max = array[0]; //Valore massimo presente nell'array A
    T min = array[0]; //Valore minimo presente nell'array B

    for (int i = 1; i < size; i++) //trovo massimo e minimo
    {
        if (max < array[i])
        {
            max = array[i];
        }

        else if (min > array[i])
        {
            min = array[i];
        }
    }

    int range = max - min + 1; //Lunghezza dell'array C

    T *tmp = new T[size]; //Array B (A ordinato)
    T *freq = new T[range]; //Array C (conteggio elementi)

    for (int i = 0; i < range; i++)
    {
        freq[i] = 0; //Inizializzo C
    }

    for (int i = 0; i < size; i++)
    {
        freq[array[i] - min]++; //Conto gli elementi presenti in A ed incremento C nella posizione dell'elemento trovato
    }

    for (int i = 1; i < range; i++)
    {
        freq[i] += freq[i - 1]; //Sommatoria degli elementi di C per trovare la posizone corretta degli elementi in B
    }

    for (int i = size - 1; i >= 0; i--)
    {
        tmp[freq[array[i] - min] - 1] = array[i]; //Nell'array B, in posizione C[i]-min-1 inserisco l'elemento A[i]
        freq[array[i] - min]--; //Decremento il conteggio
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = tmp[i]; //A = B
    }

    return freq;
    delete[] freq;
    delete[] tmp;
}
```

# Radix Sort

Questo algoritmo di ordinamento ha come complessità O(n+b)*c dove:

* n: numero di elementi da ordinare
* c: massimo numero di cifre
* b: range di numeri (es: [0,1] per binario, [0,9] per decimali)

Essendo c e b numeri irrisori, possiamo approssimare la complessità del Radix Sort ad O(n). Inoltre a differenza del counting sort l'algoritmo è stabile.

<p align="center">
  <img src="https://www.programiz.com/sites/tutorial2program/files/Radix-sort-0_0.png">
</p>


