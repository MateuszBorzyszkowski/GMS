//
// Created by mateusz on 10/27/19.
//


#include <iostream>
#include "Edge.hpp"

using namespace std;
// Definicja obiektu minimalnego drzewa rozpinającego
//---------------------------------------------------
    struct TNode {
        TNode *next;
        int v, weight;
    };

    class MSTree {
    private:
        TNode **A;                   // Tablica list sąsiedztwa
        int Alen;                     // Liczba komórek w tablicy
        int weight;                   // Waga całego drzewa
    public:
        MSTree(int n);
        ~MSTree();


        void addEdge(Edge e);

        void print();

        int getWeight();
    };


