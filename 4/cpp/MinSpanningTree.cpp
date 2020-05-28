//
// Created by mateusz on 10/27/19.
//

#include "../hpp/MinSpanningTree.hpp"

MinSpanningTree::MinSpanningTree(int n) {
    A = new TreeNode * [n];                                     // Tworzymy tablicę dynamiczną
    for(int i = 0; i < n; i++) A[i] = NULL;                     // i wypełniamy ją pustymi listami
    lengthA = n - 1;                                            // Zapamiętujemy długość tablicy
    weight = 0;                                                 // Zerujemy wagę drzewa
}

MinSpanningTree::~MinSpanningTree() {
    for(int i = 0; i <= lengthA; i++)
    {
        p = A[i];
        while(p) {
            r = p;                                              // Zapamiętujemy wskazanie
            p = p->next;                                        // Przesuwamy się do następnego elementu listy
            delete r;                                           // Usuwamy element
        }
    }

    delete [] A;                                                // Usuwamy tablicę list sąsiedztwa
}

void MinSpanningTree::addEdge(EdgeQueue e) {
    weight += e.weight;                                         // Do wagi drzewa dodajemy wagę krawędzi
    p = new TreeNode;                                           // Tworzymy nowy węzeł
    p->v = e.v2;                                                // Wierzchołek końcowy
    p->weight = e.weight;                                       // Waga krawędzi
    p->next = A[e.v1];                                          // Dodajemy p do listy wierzchołka v1
    A[e.v1] = p;

    p = new TreeNode;                                           // To samo dla krawędzi odwrotnej
    p->v = e.v1;                                                // Wierzchołek końcowy
    p->weight = e.weight;                                       // Waga krawędzi
    p->next = A[e.v2];                                          // Dodajemy p do listy wierzchołka v2
    A[e.v2] = p;
}

int MinSpanningTree::getWeight() {
    return weight;
}

