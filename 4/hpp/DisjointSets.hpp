//
// Created by mateusz on 10/27/19.
//

#include "EdgeQueue.hpp"

struct DisjointSets {                           // Definicja zbiorów rozłącznych
    int up,rank;
};

class DSSruct{
protected:
    DisjointSets * disjointSets;
    int rootU,rootV;
public:
    DSSruct(int n);
    ~DSSruct();
    void CreateSet(int v);
    int FindSet(int v);
    void JoinSets(EdgeQueue edge);
};
