//
// Created by mateusz on 11/29/19.
//
#include "../hpp/FileReader.hpp"

FileReader::FileReader() {
    file.open("../../Tests/5/test");
}

FileReader::~FileReader() {
    file.close();
}


void FileReader::reader() {

    file >> tests;
    //cout << tests << endl;
    for (int z = 0; z < tests; z++) {
        success = false;
        counter = 0;
        while (!success) {
            file >> sign;
            counter++;
            if (counter == 9) success = true;
        }
        file >> n;
        success = false;
        counter = 0;
        while (!success) {
            file >> sign;
            counter++;
            if (counter == 8) success = true;
        }
        file >> m;
        success = false;
        counter = 0;
        while (!success) {
            file >> sign;
            counter++;
            if (counter == 6) success = true;
        }

        //cout << n << " " << m << endl;

        graf = new slistEl *[n];       // Tablica list sąsiedztwa
        for (i = 0; i < n; i++) graf[i] = NULL;

        CT = new int[n];               // Tablica kolorów wierzchołków
        DT = new int[n];               // Tablica stopni wyjściowych wierzchołków
        VT = new int[n];               // Tablica numerów wierzchołków
        C = new bool[n];              // Tablica dostępności kolorów

        // Odczytujemy krawędzie grafu

        for (i = 0; i < m; i++) {
            file >> sign >> u >> sign >> v >> sign;                // Wierzchołki krawędzi
            if (i != m - 1) {
                file >> sign;
            }
            p = new slistEl;              // Tworzymy element listy
            p->v = u;
            p->next = graf[v];            // Element dołączamy do listy sąsiadów v
            graf[v] = p;

            p = new slistEl;              // To samo dla krawędzi w drugą stronę
            p->v = v;
            p->next = graf[u];            // Element dołączamy do listy sąsiadów u
            graf[u] = p;
        }


        // Rozpoczynamy algorytm kolorowania grafu

        for (v = 0; v < n; v++)          // Przeglądamy kolejne wierzchołki grafu
        {
            VT[v] = v;                    // Zapamiętujemy numer wierzchołka
            DT[v] = 0;                    // Zerujemy jego stopień wyjściowy

            for (p = graf[v]; p; p = p->next) // Przeglądamy kolejnych sąsiadów
                DT[v]++;                    // Obliczamy stopień wyjściowy wierzchołka v

                //cout << v << " => " << DT[v] << endl;

            // Sortujemy DT i VT

            d = DT[v];

            for (i = v; (i > 0) && (DT[i - 1] > d); i--) {
                DT[i] = DT[i - 1];
                VT[i] = VT[i - 1];
            }

            DT[i] = d;
            VT[i] = v;
            //cout << v << " => " << DT[v] << endl;
        }
        for (v = 0; v < n; v++) {
            mystack.push(DT[v]);
        }

        // Teraz stosujemy algorytm zachłanny, lecz wierzchołki wybieramy wg VT

        for (i = 0; i < n; i++) CT[i] = -1;

        CT[VT[0]] = 0;                  // Wierzchołek startowy
        //CT[VT[0]] = mystack.top();                  // Wierzchołek startowy


        for (v = 1; v < n; v++)          // Przeglądamy resztę grafu
        {

            for (i = 0; i < n; i++) C[i] = false;

            for (p = graf[VT[v]]; p; p = p->next) // Przeglądamy sąsiadów bieżącego wierzchołka
                if (CT[p->v] > -1) C[CT[p->v]] = true; // Oznaczamy kolor jako zajęty

            for (i = 0; C[i]; i++);        // Szukamy wolnego koloru

            CT[VT[v]] = i;                // Przypisujemy go bieżącemu wierzchołkowi
        }

        /*for (v = 0; v < n; v++)
        {
            cout << mystack.top() << endl;
            mystack.pop();
        } cout <<endl;*/
        // Wyświetlamy wyniki

        for (v = 0; v < n; v++)
            cout <<  v << " " << CT[v] + 1 << endl;
        cout << endl;

        // Usuwamy tablice dynamiczne

        for (v = 0; v < n; v++) {
            p = graf[v];
            while (p) {
                r = p;
                p = p->next;
                delete r;
            }
        }

        delete[] graf;
        delete[] CT;
        delete[] DT;
        delete[] VT;
        delete[] C;

    }
}

