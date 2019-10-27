//
// Created by mateusz on 10/27/19.
//

#include "Edge.hpp"

#ifndef GMS_DSNODE_HPP
#define GMS_DSNODE_HPP

#endif //GMS_DSNODE_HPP

// Definicja obiektu struktury zbiorów rozłącznych
//------------------------------------------------
struct DSNode
{
    int up,rank;
};

class DSStruct
{
private:
    DSNode * Z;
public:
    DSStruct(int n);
    ~DSStruct();
    void MakeSet(int v);
    int FindSet(int v);
    void UnionSets(Edge e);
};
