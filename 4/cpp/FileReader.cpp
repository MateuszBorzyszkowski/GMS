//
// Created by mateusz on 10/27/19.
//

#include "../hpp/FileReader.hpp"


FileReader::FileReader() {
    file.open("../../Tests/4/in1");
    score.open("../../Tests/4/out1");
}

FileReader::~FileReader() {
    file.close();
    score.close();
    delete [] tableFromFile;
    delete [] tableWithWeight;
}

void FileReader::kruskal() {
    file >> numberOfTests;

    tableFromFile = new int [numberOfTests];
    tableWithWeight = new int [numberOfTests];

    for (int i = 0; i < numberOfTests; i++) {
        score >> tableFromFile[i];
    }

    for (int j = 0; j < numberOfTests ; j++) {
        file >> sign >> sign >> numberOfVertices >> sign >> sign >> sign >> numberOfEdges;

        DSSruct dsSruct(numberOfVertices);                                                              // Struktura zbiorów rozłącznych
        Queue queue(numberOfEdges);                                                                     // Kolejka priorytetowa oparta na kopcu
        MinSpanningTree tree(numberOfVertices);                                                         // Minimalne drzewo rozpinające

        for(int i = 0; i < numberOfVertices; i++)
            dsSruct.CreateSet(i);                                                                       // Dla każdego wierzchołka tworzymy osobny zbiór

        for(int i = 0; i < numberOfEdges; i++)
        {
            file >> sign >> edge.v1 >> sign >> edge.v2 >> sign >> edge.weight;                          // Odczytujemy kolejne krawędzie grafu
            queue.push(edge);                                                                           // i umieszczamy je w kolejce priorytetowej
        }

        for(int i = 1; i < numberOfVertices; i++)                                                       // Pętla wykonuje się liczba wierzchołków-1 razy
        {
            do
            {
                edge = queue.front();                                                                   // Bierzemy z kolejki krawędź
                queue.pop();                                                                            // Krawędź usuwamy z kolejki
            } while(dsSruct.FindSet(edge.v1) == dsSruct.FindSet(edge.v2));
            tree.addEdge(edge);                                                                         // Dodajemy krawędź do drzewa
            dsSruct.JoinSets(edge);                                                                     // Zbiory z wierzchołkami łączymy ze sobą
        }

        tableWithWeight[j] = tree.getWeight();
    }
}

void FileReader::compare() {
    for (int i = 0; i < numberOfTests; i++) {
        cout << tableFromFile[i] << " = " << tableWithWeight[i];
        if (tableFromFile[i] == tableWithWeight[i]) {
            cout << "\tPassed." << endl;
        } else {
            cout << "\tFailed." << endl;
        }
    }
}