#pragma once

#include <iostream>
#include <vector>

using namespace std;
namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

//implementazione algoritmo bubblesort
template<Sortable T>
void BubbleSort(vector<T>& v)
{
    const unsigned int n = v.size();

    for(unsigned int i = 0; i < n - 1; i++)
    {
        for(unsigned int j = i + 1; j < n; j++)
        {
            if(v[j] < v[i])
            { 
                T tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
}

/*costruiamo un algoritmo che trasformi i vettori che gli forniamo in heap, in modo da poter poi applicare heapsort 
abbiamo ora bisgono di una funzione in grado di trasformare il vettore fornito in un heap.
costruiamo una funzione in grado di prendere in input la dimensione dell'heap(n) e l'inidice
del nodo da controllare (i)*/
template<Sortable T>
void Heapify(vector<T>& v, unsigned int n, unsigned int i)
{
    // Inizializza il nodo più grande come radice
    unsigned int index_i = i;
    unsigned int figlio_sinistro = 2 * i + 1;
    unsigned int figlio_destro = 2 * i + 2; 

    /* Con questo codice controllo che l'indice dei figli sia minore della dimensione del vettore,
    se ciò è verificato, ovvero il figlio è effettivamente esistente, lo comparo con il nodo i.
    Se il nodo i è minore di almeno uno dei suoi due figli, lo scambio di posizione con il più grande 
    dei suoi figli appunto */
    if (figlio_sinistro < n && v[figlio_sinistro] > v[index_i])
        index_i = figlio_sinistro;
    if (figlio_destro < n && v[figlio_destro] > v[index_i])
        index_i = figlio_destro;
    if (index_i != i)
    {   //swap
        T tmp = v[i];
        v[i] = v[index_i];
        v[index_i] = tmp;

        /* richiamando la funzione mi assicuro che anche dopo lo swap, si sia mantenuta la struttura 
        heap del sottoalbero (sottovettore)*/
        Heapify(v, n, index_i);
    }
}

// Implementazione di HeapSort
template<Sortable T>
void HeapSort(vector<T>& v)
{
    const int n = v.size();
    /*confrontiamo i valori dei nodi non foglie, con quelli dei rispettivi figli, e procediamo, tramite la funzione toheap
    a costruire un heap a partire dal vettore fornito*/
    for(int i = n/2 - 1; i >= 0; i--)
        Heapify(v, n, i);

    for(int i = n - 1; i > 0; i--)
    {
        /* Scambia l'elemento massimo (in cima all'heap) con l'ultimo elemento non ordinato.
         Questo pone l'elt. di valore massimo nella posizione finale nel vettore ordinato (alla prima iterazione), dopodichè
         ricostruisce l'heap escludendo l'ultimo elt. già ordinato (infatti in Heapify
        (v, i, 0), i sarà n-1, alla seconda
         iterazione n-2, ecc...). Una volta ricostruito l'heap rieffettua lo swap tra l'elt in v[0] e l'ultimo elt,
         quello in v[i], e il procedimento ricomincia un'altra volta. */
        //swap
        T tmp = v[0];
        v[0] = v[i];
        v[i] = tmp;

        Heapify(v, i, 0);
    }
}

}


