//
// Created by mateusz on 11/16/19.
//
#include <fstream>
#include <iostream>
#include "string"
#include <map>
#include <iterator>
#include <stack>

using namespace std;

class FileReader {
protected:
    ifstream file;
    ofstream outfile;
    int n, tests;
    int **graph;
    int *distance;
    int MAX = 2147483647;

public:
    FileReader();
    ~FileReader();
    void reader();
    void createGraph();
    void fillGraph();
    void printGraph();
    void bellman();
    void clear();
};
