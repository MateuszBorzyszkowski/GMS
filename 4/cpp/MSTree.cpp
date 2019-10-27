//
// Created by mateusz on 10/27/19.
//

// Definicje metod obiektu MSTree
//-------------------------------

#include "../hpp/MSTree.hpp"

// Konstruktor - tworzy tablicę pustych list sąsiedztwa
//-----------------------------------------------------
MSTree::MSTree(int n)
{
    int i;

    A = new TNode * [n];            // Tworzymy tablicę dynamiczną
    for(i = 0; i < n; i++) A[i] = NULL; // i wypełniamy ją pustymi listami
    Alen = n - 1;                   // Zapamiętujemy długość tablicy
    weight = 0;                     // Zerujemy wagę drzewa
}

// Destruktor - usuwa listy oraz tablicę sąsiedztwa
//-------------------------------------------------
MSTree::~MSTree()
{
    int i;
    TNode *p,*r;

    for(i = 0; i <= Alen; i++)
    {
        p = A[i];
        while(p)
        {
            r = p;                      // Zapamiętujemy wskazanie
            p = p->next;                // Przesuwamy się do następnego elementu listy
            delete r;                   // Usuwamy element
        }
    }

    delete [] A;                    // Usuwamy tablicę list sąsiedztwa
}

// Dodaje krawędź do drzewa
//-------------------------
void MSTree::addEdge(Edge e)
{
    TNode *p;

    weight += e.weight;             // Do wagi drzewa dodajemy wagę krawędzi
    p = new TNode;                  // Tworzymy nowy węzeł
    p->v = e.v2;                    // Wierzchołek końcowy
    p->weight = e.weight;           // Waga krawędzi
    p->next = A[e.v1];              // Dodajemy p do listy wierzchołka v1
    A[e.v1] = p;

    p = new TNode;                  // To samo dla krawędzi odwrotnej
    p->v = e.v1;                    // Wierzchołek końcowy
    p->weight = e.weight;           // Waga krawędzi
    p->next = A[e.v2];              // Dodajemy p do listy wierzchołka v2
    A[e.v2] = p;
}

// Wyświetla zawartość drzewa oraz jego wagę
//------------------------------------------
void MSTree::print()
{
    int i;
    TNode *p;

    cout << endl;
    for(i = 0; i <= Alen; i++)
    {
        cout << "Vertex " << i << " - ";
        for(p = A[i]; p; p = p->next) cout << p->v << ":" << p->weight << " ";
        cout << endl;
    }
    cout << endl << endl << "Minimal Spanning Tree Weight = " << weight << endl << endl;
}

int MSTree::getWeight() {
    return weight;
}

