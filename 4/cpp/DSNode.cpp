//
// Created by mateusz on 10/27/19.
//

// Definicje metod obiektu DSStruct
//---------------------------------

#include "../hpp/DSNode.hpp"

// Konstruktor
DSStruct::DSStruct(int n)
{
    Z = new DSNode [n];             // Tworzymy tablicę dla elementów zbiorów
}

// Destruktor
//-----------
DSStruct::~DSStruct()
{
    delete [] Z;                    // Usuwamy tablicę ze zbiorami
}

// Tworzy wpis w tablicy Z
//------------------------
void DSStruct::MakeSet(int v)
{
    Z[v].up   = v;
    Z[v].rank = 0;
}

// Zwraca indeks reprezentanta zbioru, w którym jest wierzchołek v
//----------------------------------------------------------------
int DSStruct::FindSet(int v)
{
    if(Z[v].up != v) Z[v].up = FindSet(Z[v].up);
    return Z[v].up;
}

// Łączy ze sobą zbiory z v i u
//-----------------------------
void DSStruct::UnionSets(Edge e)
{
    int ru,rv;

    ru = FindSet(e.v1);             // Wyznaczamy korzeń drzewa z węzłem u
    rv = FindSet(e.v2);             // Wyznaczamy korzeń drzewa z węzłem v
    if(ru != rv)                    // Korzenie muszą być różne
    {
        if(Z[ru].rank > Z[rv].rank)   // Porównujemy rangi drzew
            Z[rv].up = ru;              // ru większe, dołączamy rv
        else
        {
            Z[ru].up = rv;              // równe lub rv większe, dołączamy ru
            if(Z[ru].rank == Z[rv].rank) Z[rv].rank++;
        }
    }
}
