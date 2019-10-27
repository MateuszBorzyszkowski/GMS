//
// Created by mateusz on 10/27/19.
//


// Definicje metod obiektu Queue
//------------------------------

#include "../hpp/Edge.hpp"

// Konstruktor - tworzy numberOfVertices elementową tablicę heap na kopiec
//---------------------------------------------------------
Queue::Queue(int n)
{
    Heap = new Edge [n];            // Tworzymy tablicę
    hpos = 0;                       // Pozycja w kopcu
}

// Destruktor - usuwa kopiec z pamięci
//------------------------------------
Queue::~Queue()
{
    delete [] Heap;
}

// Zwraca krawędź z początku kopca
//--------------------------------
Edge Queue::front()
{
    return Heap[0];
}

// Umieszcza w kopcu nową krawędź i odtwarza strukturę kopca
//----------------------------------------------------------
void Queue::push(Edge e)
{
    int i,j;

    i = hpos++;                     // i ustawiamy na koniec kopca
    j = (i - 1) >> 1;               // Obliczamy pozycję rodzica

    // Szukamy miejsca w kopcu dla edge

    while(i && (Heap[j].weight > e.weight))
    {
        Heap[i] = Heap[j];
        i = j;
        j = (i - 1) >> 1;
    }

    Heap[i] = e;                    // Krawędź edge wstawiamy do kopca
}

// Usuwa korzeń z kopca i odtwarza jego strukturę
//-----------------------------------------------
void Queue::pop()
{
    int i,j;
    Edge e;

    if(hpos)
    {
        e = Heap[--hpos];

        i = 0;
        j = 1;

        while(j < hpos)
        {
            if((j + 1 < hpos) && (Heap[j + 1].weight < Heap[j].weight)) j++;
            if(e.weight <= Heap[j].weight) break;
            Heap[i] = Heap[j];
            i = j;
            j = (j << 1) + 1;
        }

        Heap[i] = e;
    }
}