#include <fstream>
#include <iostream>
#include <vector>
#include "MapSprites.h"

MapSprites::MapSprites() {
    spriteSizeX = 40;
    spriteSizeY = 40;
}

std::vector<std::vector<char> > MapSprites::parseDataFromMapFile(std::string pathToFile) {
    std::ifstream mapFile ((char *)pathToFile.c_str());
    std::string line;
    std::vector<std::vector<char> > tabMap;

    int rows = 0, cols = 0;

    if (mapFile.is_open()) {
        while (getline (mapFile, line)) {
            cols = line.length();
            rows++;
        }
        mapFile.clear();
        mapFile.seekg(0, std::ios::beg);

        int y = 0;

        while (getline (mapFile, line)) {
            std::vector<char> vectorLine;
            for (unsigned int x = 0; x < line.length(); x++) {
                vectorLine.push_back(line[x]);
            }
            tabMap.push_back(vectorLine);
            y++;
        }

        this->sizeX = cols;
        this->sizeY = rows;
        mapFile.close();
    }
    else {
        std::cout << "Unable to open file";
    }
    return(tabMap);
}

bool MapSprites::checkIsPositionValid(int positionX, int positionY) {
    if (positionX < 0 || positionY < 0) {
        return (false);
    }
    if (getMap()[positionY][positionX] == 'W') {
        return (false);
    }

    for(std::vector<Animal *>::iterator  iterator = animalsList->begin(); iterator != animalsList->end(); ++iterator) {
        Animal * animal = ((Animal *)*iterator);
        if (animal->getPositionX() == positionX && animal->getPositionY() == positionY) {
            return (false);
        }
    }
    return (true);
}