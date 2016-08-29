#include <iostream>
#include "Window.h"

Window::Window(sf::VideoMode mode, std::string title) : sf::RenderWindow(mode, title) {
    textureGrass.loadFromFile("resources/sprites/grass.png");
    textureWater.loadFromFile("resources/sprites/water.png");
    textureSand.loadFromFile("resources/sprites/sand.png");

    this->spriteGrass = sf::Sprite(textureGrass);
    this->spriteWater = sf::Sprite(textureWater);
    this->spriteSand = sf::Sprite(textureSand);
}

void Window::displayAnimals() {
    std::vector<Animal *> * listAnimals = this->getMapSprites()->getAnimalsList();
    for(std::vector<Animal *>::iterator  it = listAnimals->begin(); it != listAnimals->end(); ++it) {
        sf::Texture texture;
        Animal * animal = (Animal *) *it;
        texture.loadFromFile(animal->getSpritePath());
        sf::Sprite sprite = sf::Sprite(texture);
        sprite.setPosition(animal->getPositionX() * 40, animal->getPositionY() * 40);
        draw(sprite);
    }
}

void Window::displaySprites() {
    for (int i = 0; i<Window::getMapSprites()->getSizeX(); i++) {
        for (int j = 0; j < mapSprites->getSizeY(); j++) {
            switch (mapSprites->getMap()[i][j]) {
                case 'G' : {
                    spriteGrass.setPosition(j*mapSprites->getSpriteSizeX(), i*mapSprites->getSpriteSizeY());
                    this->draw(spriteGrass);
                    break;
                }
                case 'S' : {
                    spriteSand.setPosition(j*mapSprites->getSpriteSizeX(), i*mapSprites->getSpriteSizeY());
                    this->draw(spriteSand);
                    break;
                }
                case 'W' : {
                    spriteWater.setPosition(j*mapSprites->getSpriteSizeX(), i*mapSprites->getSpriteSizeY());
                    this->draw(spriteWater);
                    break;
                }
            }
        }
    }
}