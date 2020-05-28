//
// Created by mateusz on 11/17/19.
//
#include "../hpp/FileReader.hpp"


FileReader::FileReader() {
    file.open("../../Tests/2/input");
    score.open("../../Tests/2/output");
}

FileReader::~FileReader() {
    delete[] tableScore;
    delete[] tableFile;
    file.close();
    score.close();
}

void FileReader::readScore() {
    tableScore = new int [l];
    tableFile = new int [l];
    for(int i = 0; i < l; i++) {
        score >> tableScore[i];
    }
}

void FileReader::compare() {
    for (int i = 0; i < l; i++) {
        if (tableFile[i] == tableScore[i]) {
            cout << "\tPassed: ";
        } else {
            cout << "\tFailed: ";
        }
        cout << tableFile[i] << " = " << tableScore[i] << endl;
    }
}

int FileReader::minimal(int *dystans, bool *odwiedzony, int n) {
    int min_dystans = MAXINT;
    int min = MAXINT;

    for (int i = 0; i < n; i++)
        if (!odwiedzony[i] && dystans[i] <= min_dystans)
        {
            min_dystans = dystans[i];
            min = i;

        }
    //cout << min << endl;
    return min;
}

int FileReader::dijkstra(int **graphl, int pocz, int meta, int n) {
    int *dystans;
    bool *odwiedzony;
    dystans = new int[n];
    odwiedzony = new bool[n];
    //cout << pocz << " " << meta << " " << n << endl;

    for (int i = 0; i < n; i++)
    {
        dystans[i] = MAXINT;
        odwiedzony[i] = false;

    }
    dystans[pocz] = 0;

    for (int i = 0; i < n; i++)
    {
        int pom = minimal(dystans, odwiedzony, n);
        odwiedzony[pom] = true;
        for (int j = 0; j < n; j++)
        {
            if (!odwiedzony[j])
            {
                if ((graphl[pom][j] && dystans[pom] != MAXINT) && (dystans[pom] + graphl[pom][j] < dystans[j]))
                    dystans[j] = dystans[pom] + graphl[pom][j];

            }


        }

    }

    //if (dystans[meta] != MAXINT) cout << dystans[meta] << "\n";
    //else cout << "nie ma\n";

    delete[] dystans;
    delete[] odwiedzony;

    return dystans[meta];
}

void FileReader::reader() {
    file >> s;
    //cout << s << endl;

    for (int z = 0; z < s; z++) {
        //cout << "======== " << z + 1 << " =========" << endl;
        file >> n;
        //cout << n << endl;

        graph = new int* [n];
        for (int i = 0; i < n; i++) {
            graph[i] = new int[n]; //cout << i << endl;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            file >> name >> k;
            mymap.insert(pair<string, int>(name, i));

            while (k--) {
                file >> dest >> cost;
                dest--;
                //cout << dest << " " << cost << endl;
                graph[i][dest] = cost;
                //graph[dest][i] = cost;
            }
        }


        /*cout << "\n";
        for (int i = 0; i < n; i++)
        {
        for(int j = 0; j < n; j++)
        {
        cout << graph[i][j] << " ";
        }
        cout << "\n"; cout << endl;
        }*/


        file >> road;
        //cout << endl << road << endl;
        while (road--) {
            file >> startName >> finishName;
            it = mymap.find(startName);
            it2 = mymap.find(finishName);
            if (it == mymap.end()) cout << "No pair in map" << endl;
            else start = it->second;
            if (it2 == mymap.end()) cout << "No pair in map" << endl;
            else finish = it2->second;


            tableFile[p++] = dijkstra(graph, start, finish, n);
        }
        //mymap.clear();
        for (int i = 0; i < n; i++) {
            delete[] graph[i];
        }
        delete[] graph;
    }
}