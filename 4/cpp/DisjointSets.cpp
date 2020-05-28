//
// Created by mateusz on 10/27/19.
//

#include "../hpp/DisjointSets.hpp"


DSSruct::DSSruct(int n) {
    disjointSets = new DisjointSets [n];
}

DSSruct::~DSSruct() {
    delete [] disjointSets;
}

void DSSruct::CreateSet(int v) {                                                                                            // Tworzy zbiór
    disjointSets[v].up   = v;
    disjointSets[v].rank = 0;
}

int DSSruct::FindSet(int v) {                                                                                               // Zwraca inx zbioru, w któryym znajduje się wierzchołek
    if(disjointSets[v].up != v) disjointSets[v].up = FindSet(disjointSets[v].up);
    return disjointSets[v].up;
}

void DSSruct::JoinSets(EdgeQueue edge) {                                                                                    // Łączenie zbiorów
    rootU = FindSet(edge.v1);                                                                                               // Wyznaczamy korzeń drzewa z węzłem u
    rootV = FindSet(edge.v2);                                                                                               // Wyznaczamy korzeń drzewa z węzłem v
    if(rootU != rootV) {                                                                                                    // Korzenie muszą być różne
        if(disjointSets[rootU].rank > disjointSets[rootV].rank)                                                             // Porównujemy rangi drzew
            disjointSets[rootV].up = rootU;                                                                                 // rootU większe, dołączamy rootV
        else {
            disjointSets[rootU].up = rootV;                                                                                 // równe lub rootV większe, dołączamy rootU
            if(disjointSets[rootU].rank == disjointSets[rootV].rank) disjointSets[rootV].rank++;
        }
    }
}
