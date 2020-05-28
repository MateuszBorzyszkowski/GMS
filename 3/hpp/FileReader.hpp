//
// Created by mateusz on 11/21/19.
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
    ifstream file;;
    stack <int> mystack;
    int n, m, u, v, l, tests;
    int k = 0;
    char sign;
    int **graph;

public:
    FileReader();
    ~FileReader();
    void reader();
    void createGraph();
    void fillGraph();
    void printGraph();
    void euler(int v);
    void clear();
};

