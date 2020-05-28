//
// Created by mateusz on 10/27/19.
//

#ifndef GMS_EDGEQUEUE_HPP
#define GMS_EDGEQUEUE_HPP


struct EdgeQueue {                           // Struktura opisująca krawędź, czyli jej wierzchołki i wagę
    int v1, v2, weight;
};

class Queue {                                // Kolejka piorytetowa oparta na kopcu przechowująca krawędzie
protected:                                   // od najmniejszej do największej wagi
    EdgeQueue * Heap;
    EdgeQueue e;
    int heapPosition;
    int i,j;
public:
    Queue(int n);
    ~Queue();
    EdgeQueue front();
    void push(EdgeQueue e);
    void pop();
};

#endif //GMS_EDGEQUEUE_HPP
