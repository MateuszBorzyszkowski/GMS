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

void FileReader::algorithm() {
    file >> numberOfTests;

    tableFromFile = new int [numberOfTests];
    tableWithWeight = new int [numberOfTests];

    for (int i = 0; i < numberOfTests; i++) {
        score >> tableFromFile[i];
    }

    for (int j = 0; j < numberOfTests ; j++) {
        file >> sign >> sign >> numberOfVertices >> sign >> sign >> sign >> numberOfEdges;      // Czytamy liczbę wierzchołków i krawędzi

        DSStruct Z(numberOfVertices);                  // Struktura zbiorów rozłącznych
        Queue Q(numberOfEdges);                     // Kolejka priorytetowa oparta na kopcu
        MSTree T(numberOfVertices);                    // Minimalne drzewo rozpinające

        for(int i = 0; i < numberOfVertices; i++)
            Z.MakeSet(i);                 // Dla każdego wierzchołka tworzymy osobny zbiór

        for(int i = 0; i < numberOfEdges; i++)
        {
            file >> sign >> edge.v1 >> sign >> edge.v2 >> sign >> edge.weight; // Odczytujemy kolejne krawędzie grafu
            Q.push(edge);                    // i umieszczamy je w kolejce priorytetowej
        }

        for(int i = 1; i < numberOfVertices; i++)          // Pętla wykonuje się numberOfVertices - 1 razy !!!
        {
            do
            {
                edge = Q.front();              // Pobieramy z kolejki krawędź
                Q.pop();                    // Krawędź usuwamy z kolejki
            } while(Z.FindSet(edge.v1) == Z.FindSet(edge.v2));
            T.addEdge(edge);                 // Dodajemy krawędź do drzewa
            Z.UnionSets(edge);               // Zbiory z wierzchołkami łączymy ze sobą
        }

        // Wyświetlamy wyniki
        tableWithWeight[j] = T.getWeight();
        //T.print();

    }
}

void FileReader::compare() {
    bool success = false;
    for (int i = 0; i < numberOfTests; i++) {
        //cout << tableFromFile[i] << " = " << tableWithWeight[i] << endl;
        if (tableFromFile[i] == tableWithWeight[i]) success = true;
    }
    if (success) cout << "TEST PASSED." << endl;
}