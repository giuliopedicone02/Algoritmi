# Tabelle Hash

Una tabella hash è una sequenza di elementi costituita da due parti:

* Una chiave k: contraddistingue ogni elemento dagli altri
* Una informazione i: associata alla chiave

Le operazioni effettuabili sono 3:

* insert(elem e, chiave k)
* delete(elem e, chiave k)
* search(chiave k)

Esistono due possibili metodologie di implementazione:

* Tabelle Hash
* Tabelle ad indirizzamento aperto


# Tabelle Hash

Una funzione hash è una funzione che data una chiave k ∈ U restituisce la posizione della tabella in cui l’elemento con chiave k viene memorizzato.

## Collisioni

Due chiavi k1 e k2 collidono quando corrispondono alla stessa posizone della tabella ovvero quando h(k1)=h(k2)

## Funzioni hash

Esistono due metodi per ottenere ottime funzioni hash e sono i seguenti:

* Metodo della moltiplicazione
* Metodo della divisione

## Metodo della moltiplicazione

**Funzione hash:** h(k) = k mod m

## Metodo della divisione

**Funzione hash:** h(k) = floor(m*(kA mod 1))

Nota bene: A è un numero compreso tra [0,1] ed è circa 0.618

## Risoluzione delle collisoni tramite concatenazione (chaining)

Gli elementi collidenti vengono inseriti nella stessa posizione della tabella in una lista concatenata

Questo comporta che inserimento e cancellazione avverranno sempre in O(1), la ricerca in tempo O(n)

**Fattore di carico:** α=n/m

Si definisce fattore di carico il rapporto tra il numero n degli elementi memorizzati e la dimensione m della tabella

* α<1: molte posizoni disponibili rispetto agli elementi memorizzati
* α=1: numero di elementi memorizzati uguale alla dimensione della tabella
* α>1: molti elementi memorizzati rispetto alla dimensione della tabella

# Tabelle ad indirizzamento aperto

<p align="center">
  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQGeNr_8YaU46uWUe9iXzSoXd-MGamr6Bcda980hgH7yn8NNOX8lr4srWxyliT__jfczWA&usqp=CAU">
</p>

Le operazioni di inserimento, cancellazione e ricerca hanno tutti costo O(1)

```c++
    directAddressSearch(T,k)
    {
        return T[k]
    }

    directAddressInsert(T,x)
    {
        T[key[x]]=x
    }

    directAddressDelete(T,x)
    {
        T[key[x]]=NULL;
    }
```

**Fattore di carico:** α=n/m

* n: |K| numero di chiavi utilizzate
* m: |U| dimensione della tabella

## Tecniche di scansione 

### Scansione lineare

**Funzione hash:** h(k,i)=(h'(k)+i) mod m

### Scansione quadratica

**Funzione hash:** h(k,i)=(h'(k)+ c1*i + c2 * i^2) mod m

### Hashing doppio

**Funzione hash:** h(k,i)=(h1(k) + ih2(k)) mod m

