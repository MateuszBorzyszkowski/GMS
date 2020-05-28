//
// Created by mateusz on 11/29/19.
//
#include <fstream>
#include <iostream>
#include "string"
#include <map>
#include <iterator>
#include <stack>

using namespace std;


struct slistEl
{
    slistEl * next;                 // Następny element listy;
    int v;                          // Wierzchołek docelowy
};

class FileReader {
protected:
    ifstream file;
    int n, m, i, u, v, d, counter, tests, *CT, *DT, *VT;
    slistEl **graf, *p, *r;
    bool *C, success;
    char sign;
    stack <int> mystack;
public:
    FileReader();
    ~FileReader();
    void reader();
};




