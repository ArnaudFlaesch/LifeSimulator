#ifndef LIFESIMULATOR_MAP_H
#define LIFESIMULATOR_MAP_H

#include <string>
#include <vector>
#include "species/Animal.h"

class MapSprites {

private:
    int sizeX, sizeY;
    int spriteSizeX, spriteSizeY;
    std::vector<std::vector<char> > map;
    std::vector<Animal *> * animalsList;

public:
    MapSprites();
    std::vector<std::vector<char> > parseDataFromMapFile(std::string pathToFile);
    bool checkIsPositionValid(int positionX, int positionY);

    const std::vector<std::vector<char> > &getMap() const {
        return map;
    }

    void setMap(const std::vector<std::vector<char> > &map) {
        MapSprites::map = map;
    }

    int getSizeX() const {
        return sizeX;
    }

    void setSizeX(int sizeX) {
        MapSprites::sizeX = sizeX;
    }

    int getSizeY() const {
        return sizeY;
    }

    void setSizeY(int sizeY) {
        MapSprites::sizeY = sizeY;
    }

    int getSpriteSizeX() const {
        return spriteSizeX;
    }

    void setSpriteSizeX(int spriteSizeX) {
        MapSprites::spriteSizeX = spriteSizeX;
    }

    int getSpriteSizeY() const {
        return spriteSizeY;
    }

    void setSpriteSizeY(int spriteSizeY) {
        MapSprites::spriteSizeY = spriteSizeY;
    }

    std::vector<Animal *> *getAnimalsList() const {
        return animalsList;
    }

    void setAnimalsList(std::vector<Animal *> *animalsList) {
        MapSprites::animalsList = animalsList;
    }
};

#endif //LIFESIMULATOR_MAP_H