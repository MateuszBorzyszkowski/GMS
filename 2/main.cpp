#include <iostream>
#include "hpp/FileReader.hpp"

int main() {
    FileReader fileReader;

    fileReader.readScore();
    fileReader.reader();
    fileReader.compare();

    return 0;
}