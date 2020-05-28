//
// Created by mateusz on 11/21/19.
//
#include "../hpp/FileReader.hpp"


FileReader::FileReader() {
    file.open("../../Tests/3/input");
}

FileReader::~FileReader() {
    file.close();
}

void FileReader::reader() {
    file >> tests;
    //cout << tests << endl;

    for (int z = 0; z < tests; z++) {
        file >> sign >> sign >> n >> sign >> sign >> sign >> m;
        //cout << n << " " << m << endl;

        createGraph();

        while(m--) {
            file >> sign >> u >> sign >> v >> sign;
            //cout << u << " " << v << endl;
            fillGraph();
        }

        euler(0);
        printGraph();
        clear();

    }
}

void FileReader::createGraph() {
    graph = new int * [n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int [n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void FileReader::fillGraph() {
    graph[u][v] ++;
    graph[v][u] ++;
}

void FileReader::printGraph() {
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    */
    ///*
    //cout << mystack.size() << endl;
    l = mystack.size();
    //cout << "Euler cycle for " <<  ++k << " case: ";
    for (int i = 0; i < l; i++) {
        //cout << "\033[0;32m" << mystack.top() << "\033[0m ";
        cout << mystack.top();
        mystack.pop();
        if (mystack.size() != 0) cout << " ";
    }
    cout << endl;
    //cout << "\033[0;32mbold red text\033[0m\n";

    //*/
}

void FileReader::euler(int v) {
    for (int i = 0; i < n; i++) {
        while(graph[v][i]) {
            graph[v][i] --;
            graph[i][v] --;
            euler(i);
        }
    }
    mystack.push(v);
}

void FileReader::clear() {
    while (!mystack.empty()) {
        cout << "ERROR: Stack is not empty!" << endl;
        break;
    }

    for (int i = 0; i < n; i++) {
        delete[]  graph[i];
    }
    delete[] graph;
}