//
// Created by mateusz on 10/27/19.
//

#include <iostream>
#include <fstream>
#include "MinSpanningTree.hpp"
#include "DisjointSets.hpp"

using namespace std;

class FileReader {
protected:
    ifstream file;
    ifstream score;
    int numberOfVertices, numberOfEdges;
    EdgeQueue edge;
    int numberOfTests;
    char sign;
    int  *tableFromFile, *tableWithWeight;
public:
    FileReader();
    ~FileReader();
    void kruskal();
    void compare();
};
