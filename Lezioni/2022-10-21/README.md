# Heap

Struttura dati che può essere considerata come un albero binario **quasi completo**

Quasi completo significa che tutti i livelli, tranne l’ultimo, sono completi: possono mancare alcune foglie consecutive a partire dall’ultima foglia a destra.

**Altezza di un heap:** log(n)

## Coda di priorità

Struttura dati dove ciascuna **chiave** rappresenta la sua **priorità**

## Max Heap e Min Heap

* Max Heap: node->parent >= node
* Min Heap: node->parent <= node

## Figli e parent di un nodo
```c++
    int left(int i)
    {
        return 2 * i;
    }

    int right(int i)
    {
        return 2 * i + 1;
    }

    int parent(int i)
    {
        return i / 2;
    }
```

## Inserimento in un Max Heap: O(log n)

```c++
 maxHeap_insert(T x)
 {
    heapsize++;
    queue[heapsize] = new T(x);
    int i = heapsize;
    while(i>1||queue[parent(i)]<queue[i])
    {
        swap(i,parent(i));
        i=parent(i);
    }
 }
```

## Procedura Heapify nei Max Heap: O(log n)

Viene chiamata quando i figli sinistro e destro di un nodo x sono max-heap, ma x è più piccolo dei suoi figli violandone quindi la proprietà.

```c++
 void maxHeapify(int index)
 {
    int massimo = index;
    int l = left(index);
    int r = right(index);

    if (l <= heapsize && queue[l]>queue[index])
    {
         massimo=l;
    }
    else
    {
        massimo=index;
    }

    if (r <= heapsize && queue[r]>queue[massimo])
    {
        massimo = r;
    }

    if(massimo!=index)
    {
        swap(index,massimo);
        maxHeapify(massimo);
    }
 }
```

## Estrazione del massimo: O(log n)

```c++
 T* extractMax(int index)
 {
    if(heapsize<1)
    {
        return nullptr;
    }

    swap(1, heapsize);
    heapsize--;
    maxHeapify(1);
    return queue[heapsize + 1];
 }
```

## Build-Max-Heap: O(n log n)
```c++
 void buildMaxHeap()
 {  
    heapsize=queueLength;

    for(int i=floor(queueLength/2);i>=0;i--)
    {
        maxHeapify(i);
    }
 }
```

## Heapsort: O(n log n)
```c++
 void heapSort()
 {  
    buildMaxHeap();
    for(int i=queueLength;i>=1;i--)
    {
        swap(1,i);
        swap(heapsize,heapsize-1);
        maxHeapify(1);
    }
 }
```
