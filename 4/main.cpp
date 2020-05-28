#include <iostream>
#include <fstream>

#include "hpp/FileReader.hpp"

int main()
{
    FileReader fileReader;

    fileReader.kruskal();
    fileReader.compare();

    return 0;
} 