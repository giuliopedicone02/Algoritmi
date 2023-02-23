# Alberi Rosso Neri

Struttura dati che può essere considerata come un albero binario **quasi bilanciato**

## Le 5 regole di un Albero Rosso Nero

1. Ogni nodo può essere rosso o nero
2. La radice è nera
3. Le foglie sono nere
4. Un nodo rosso può avere solo figli neri
5. Per ogn nodo n, tutti i percorsi che vanno da n alle sue foglie discendenti devono avere lo stesso numero di nodi neri **(B-Altezza)**

**Altezza massima un albero rosso nero:** 2log(n+1)

## Rotazioni: O(1)

Sono delle operazioni di ristrutturazione locale dell’albero che mantengono soddisfatte le proprietà degli alberi rosso-neri.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/3/31/Tree_rotation_animation_250x250.gif">
</p>


### Rotazione a sinistra
```c++
    void leftRotate(T key)
    {
        BSTNode<T> *x = search(key);

        if (!x || x->right == nullptr)
        {
            return;
        }

        BSTNode<T> *y = x->right; //y figlio destro di x
        x->right = y->left; //Il sottoalbero sinistro di y diventa il sottoalbero destro di x

        if (y->left != nullptr) //Se y ha un figlio sinistro
        {
            y->left->parent = x; //Il suo genitore diventa x
        }

        y->parent = x->parent; //Il genitore di y diventa il genitore di x

        if (x->parent == nullptr) //Se x non ha un genitore (ovvero x è la radice)
        {
            root = y; //La radice diventa y
        }
        else if (x == x->parent->left) //Se x è figlio sinistro
        {
            x->parent->left = y; //Il suo genitore diventa y
        }
        else //Se x è figlio destro
            x->parent->right = y; //Il suo genitore diventa y

        y->left = x; //Il figlio sinistro di y diventa x
        x->parent = y; //Il genitore di x diventa y
    }
```

### Rotazione a destra
```c++
     void rightRotate(T key)
    {
        BSTNode<T> *x = search(key);

        if (!x || x->left == nullptr)
        {
            return;
        }

        BSTNode<T> *y = x->left; // y figlio sinistro di x
        x->left = y->right; //Il figlio sinistro di x siventa il figlio destro di y

        if (y->right != nullptr) //Se y ha un figlio destro 
        {
            y->right->parent = x; //Il suo genitore diventa x
        }

        y->parent = x->parent; //Il genitore di y diventa il genitore di x

        if (x->parent == nullptr) //Se x non ha un genitore (ovvero x è la radice)
        {
            root = y; //La radice diventa y
        }
        else if (x == x->parent->right) //Se x è figlio sinistro
        {
            x->parent->right = y; //Il suo genitore diventa y
        }
        else //Se x è figlio destro
            x->parent->left = y; //Il suo genitore diventa y

        y->right = x; //Il figlio destro di y diventa x
        x->parent = y; //Il genitore di x diventa y
    }
```

## Inserimento: O(log n)

Identico all'inserimento di un BST con l'unica aggiunta di imporre l'inserimento di un nodo rosso (di default) ed il richiamo della funzione RB-insert-fixup() per garantire il rispetto delle 5 regole degli alberi rosso neri.

```c++
    void Tree_insert(T, z) 
    {
        y = NULL;
        x = T.root;                         // T.root indica la radice dell'albero T
        while(x != NULL) {
            y = x;                          // y è l'ultimo nodo visitato
            if(z.key <= x.key) x = x.left;
            else x = x.right;
        }
        z.p = y;                            // z.p indica il padre del nodo z
        if(y == NULL) T.root = z;
        else if(z.key <= y.key) y.left = z;
        else y.right = z;

        z.left=NULL;
        z.right=NULL;
        z.color=RED;
        RB-Insert-fixup(T,z)
    }
```

## RB-Insert-Fixup: O(log n)

![RB-INSERT FIXUP](https://www.codesdope.com/staticroot/images/ds/rb20.png)

Si divide in tre casi:

1. Lo zio è rosso
2. Lo zio di z è nero e z è un figlio destro
3. Lo zio di z è nero e z è un figlio sinistro

Soluzioni:

1. Il padre di z e suo fratello (zio di z) y – entrambi rossi – vengono colorati di nero; il nonno di z – nero – viene colorato di rosso e diventa il nuovo z.

![RB-INSERT FIXUP CASO 1](https://www.codesdope.com/staticroot/images/ds/rb21.png)
2. Ruotiamo il padre di z a sinistra e ci riconduciamo al caso 3
![RB-INSERT FIXUP CASO 2](https://www.codesdope.com/staticroot/images/ds/rb23.png)
3. Scambiamo il colore del padre di z (rosso) con quello del nonno (nero) e ruotiamo il padre di z a destra.
![RB-INSERT FIXUP CASO 3](https://www.codesdope.com/staticroot/images/ds/rb24.png)

```c++
  void RB-Insert-fixup(T,z)
  while (z.p.color == RED) { //Se il genitore di z è rosso (Violata la proprietà 4)
    if (z.p == z.p.p.left) {  // Se il genitore di z è un figlio sinistro
         y = z.p.p.right //y = zio di z
         if (y.color == RED){ // CASO 1 - LO ZIO E ROSSO
             z.p.color = BLACK; // Il genitore di z diventa rosso
             y.color = BLACK; // Lo zio diventa nero
             z.p.p.color = RED; //Il nonno diventa rosso
             z = z.p.p; //z diventa suo nonno
         }
         else { // CASO 2 - LO ZIO è NERO E Z è figlio destro - ci riconduciamo al caso 3
             if z == z.p.right {
                  z = z.p; //z diventa il suo genitore
                  LEFT-Rotate(T,z); // Ruotiamo z a sinistra
             } // CASO 3 - LO ZIO è NERO e z è figlio sinistro
             z.p.color = BLACK; // Il genitore di z diventa nero
             z.p.p.color = RED; // Il nonno diventa rosso
             RIGHT-Rotate(T,z.p.p); // Ruotiamo a destra il nonno di z
         }
    }
    else { // Il genitore di z è figlio destro (caso speculare)
         y = z.p.p.left; //y = zio di z
          if (y.color == RED){ // CASO 1 - LO ZIO E ROSSO
             z.p.color = BLACK; // Il genitore di z diventa rosso
             y.color = BLACK; // Lo zio diventa nero
             z.p.p.color = RED; //Il nonno diventa rosso
             z = z.p.p; //z diventa suo nonno
         }
         else { // CASO 2 - LO ZIO è NERO e Z è figlio sinistro - ci riconduciamo al caso 3
             if z = z.p.left {
                  z = z.p; //z diventa il suo genitore
                  RIGHT-Rotate(T,z); //Ruotiamo a destra z
             } //CASO 3 - LO ZIO è NERO e Z è figlio destro
             z.p.color = BLACK; // Il genitore di z diventa nero
             z.p.p.color = RED; // Il nonno diventa rosso
             LEFT-Rotate(T,z.p.p); // Ruotiamo a sinistra il nonno di z
         }
    }

    T.root.color = BLACK; //Per assicurarci che la proprietà 2 sia rispettata coloriamo di nero la radice
  }
```

## Funzione Trapianta: O(1)

Questa funzione verrà utilizzata durante la procedura di eliminazione di un nodo dell'albero rosso-nero, il primo parametro (u) è il nodo da eliminare, il secondo (v) è la radice del sottoalbero che sostituirà u.

```c
    RB-Transplant(T,u,v)
    {
        if u.p == NULL      //Se il nodo u è la radice, imposta v come nuova radice dell'albero
            T.root = v
        else u == u.p.left  //Se il nodo u è figlio sinistro, imposta v come nuovo figlio sinistro
            u.p.left = v
        else
            u.p.right = v   //Altrimenti imposta v come nuovo figlio destro
        
        v.p = u.p           // Il parent di v è uguale al parent di u
    }
```

## Funzione Delete: O(log n)

Questa funzione elimina il nodo z dall'albero e si distingue in tre casi:

1. Il nodo z ha solo un figlio destro
2. Il nodo z ha solo un figlio sinistro
3. Il nodo z ha entrambi i figli

Il nodo x è un nodo ausiliario che ci tornerà utile quando richiameremo la funzione RB-DELETE-FIXUP()
Il nodo y è un nodo ausiliario che tiene traccia delle possibili violazioni alle regole dell'albero rosso nero.

```c
  RB-DELETE(T, z)
    y = z 
    y.original-color = y.color

    if z.left == NULL                       // CASO 1 - Il nodo z ha solo un figlio destro
        x = z.right 
        RB-Transplant(T, z, z.right)
    else if z.right == NULL                 // CASO 2 - Il nodo z ha solo un figlio sinistro
        x = z.left
        RB-Transplant(T, z, z.left)
    else                                    // CASO 3 - Il nodo z ha entrambi i figli
        y = TREE-MINIMUM(z.right)           // Cerco il minimo del sottoalbero destro e lo memorizzo in y
        y.original-color = y.color
        x = y.right

        if y.p == z                         // Se il padre di y è z, impostiamo il parent di x come y
            x.p = y
        else RB-Transplant(T, y, y.right)   // Altrimenti eliminiamo y e lo sostituiamo con il suo figlio destro
            y.right = z.right               // Il figlio destro di y è uguale al figlio destro di z
            y.right.p = y                   // Il parent del figlio destro di y sarà y
        
        RB-Transplant(T, z, y)              // Eliminiamo il nodo z e lo sostituiamo con y
        y.left = z.left                     // Il figlio sinistro di y sarà uguale al figlio sinistro di z
        y.left.p = y                        // Il parent del figlio sinistro di y sarò y
        y.color = z.color                   // y eredita il colore di z

    if y.original-color == BLACK            // Se il colore originale di y era nero, si verifica la condizione del doppionero
        RB-DELETE-FIXUP(T, x)               // Richiamiamo quindi RB-DELETE-FIXUP(T,x) per ripristinare le 5 regole dell'RB-TREE
```