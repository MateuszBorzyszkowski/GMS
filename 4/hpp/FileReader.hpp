//
// Created by mateusz on 10/27/19.
//

#include <iostream>
#include <fstream>
#include "MSTree.hpp"
#include "DSNode.hpp"

using namespace std;

class FileReader {
protected:
    ifstream file;
    ifstream score;
    int numberOfVertices, numberOfEdges;                        // Liczba wierzchołków i krawędzi
    Edge edge;
    int numberOfTests;
    char sign;
    int  *tableFromFile, *tableWithWeight;
public:
    FileReader();
    ~FileReader();
    void algorithm();
    void compare();
};
