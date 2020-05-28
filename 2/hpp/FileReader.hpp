//
// Created by mateusz on 11/17/19.
//
#include <fstream>
#include <iostream>
#include "string"
#include <map>
#include <iterator>
#include <vector>

using namespace std;

class FileReader {
protected:
    ifstream file, score;
    map <string, int> mymap;
    map <string, int>::iterator it;
    map <string, int>::iterator it2;
    vector <vector <int> > myvector;
    int **graph;
    int *tableFile, *tableScore;
    int s, n;
    const int MAXINT = 2147483647;
    string name, startName, finishName;
    int start, finish;
    int k, dest, cost, road;
    int p = 0;
    int l = 95;

public:
    FileReader();
    ~FileReader();
    void readScore();
    void compare();
    int minimal(int *dystans, bool *odwiedzony, int n);
    int dijkstra(int **graphl, int pocz, int meta, int n);
    void reader();
};