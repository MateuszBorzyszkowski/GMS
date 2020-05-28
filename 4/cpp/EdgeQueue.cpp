//
// Created by mateusz on 10/27/19.
//

#include "../hpp/EdgeQueue.hpp"

Queue::Queue(int n) {
    Heap = new EdgeQueue [n];                       // Tworzymy tablicę
    heapPosition = 0;                               // Pozycja w kopcu
}

Queue::~Queue() {
    delete [] Heap;
}

EdgeQueue Queue::front() {                          // Zwraca z początku kopca wartośc krawędzi
    return Heap[0];
}

void Queue::push(EdgeQueue e) {

    i = heapPosition++;                             // 'i' ustawiamy na koniec kopca
    j = (i - 1) >> 1;                               // Obliczamy pozycję rodzica

    while(i && (Heap[j].weight > e.weight)) {       // Szukamy miejsca w kopcu dla edge
        Heap[i] = Heap[j];
        i = j;
        j = (i - 1) >> 1;
    }

    Heap[i] = e;                                    // Krawędź edge wstawiamy do kopca
}

void Queue::pop() {

    if(heapPosition) {
        e = Heap[--heapPosition];

        i = 0;
        j = 1;

        while(j < heapPosition) {
            if((j + 1 < heapPosition) && (Heap[j + 1].weight < Heap[j].weight)) j++;
            if(e.weight <= Heap[j].weight) break;
            Heap[i] = Heap[j];
            i = j;
            j = (j << 1) + 1;
        }

        Heap[i] = e;
    }
}