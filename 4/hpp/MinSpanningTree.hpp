//
// Created by mateusz on 10/27/19.
//


#include <iostream>
#include "EdgeQueue.hpp"

using namespace std;

struct TreeNode {
    TreeNode *next;
    int v, weight;
};

class MinSpanningTree {
protected:
    TreeNode **A;                   // Tablica list sąsiedztwa
    TreeNode *p,*r;
    int lengthA;                    // Liczba komórek w tablicy
    int weight;                     // Waga całego drzewa
public:
    MinSpanningTree(int n);
    ~MinSpanningTree();
    void addEdge(EdgeQueue e);
    int getWeight();
};


