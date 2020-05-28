//
// Created by mateusz on 11/16/19.
//

#include "../hpp/FileReader.hpp"

FileReader::FileReader() {
    file.open("../../Tests/1/in");
    outfile.open("../../Tests/1/outputfile");
}

FileReader::~FileReader() {
    file.close();
    outfile.close();
}


void FileReader::reader() {
    file >> tests;
    //cout << tests << endl;

    for (int z = 0; z < tests; z++) {
        file >>  n ;
        //cout << n << endl;

        createGraph();
        fillGraph();

        for (int i = 1; i < n; i++) {
            bellman();
            for (int j = 0; j < n; j++) {
                //cout << distance[j] << " ";
                if(distance[j] == MAX) {
                    outfile << 0 << " ";
                } else
                    outfile << distance[j] << " ";
            }
            //cout << endl;
            outfile << endl;
        }
        outfile << endl;
        //cout << endl;

        printGraph();
        clear();
    }
}

void FileReader::createGraph() {
    graph = new int * [n];
    distance = new int [n];

    for (int i = 0; i < n; i++) {
        graph[i] = new int [n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        distance[i] = MAX;
    }
    distance[0] = 0;
}

void FileReader::fillGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> graph[i][j];
        }
    }
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


}

void FileReader::bellman() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (distance[i] != MAX && graph[i][j] != 0 && distance[j] > distance[i] + graph[i][j]) {
                distance[j] = distance[i] + graph[i][j];
            }
        }
    }
}

void FileReader::clear() {
    for (int i = 0; i < n; i++) {
        delete[]  graph[i];
    }
    delete[] graph;
    delete[] distance;
}
