//
// Created by mateusz on 10/27/19.
//

#ifndef GMS_EDGE_HPP
#define GMS_EDGE_HPP
// Definicja obiektu kolejki priorytetowej
//----------------------------------------


struct Edge
{
    int v1,v2,weight;               // Wierzchołki krawędzi, waga krawędzi
};

class Queue
{
private:
    Edge * Heap;
    int hpos;
public:
    Queue(int n);
    ~Queue();
    Edge front();
    void push(Edge e);
    void pop();
};

#endif //GMS_EDGE_HPP
