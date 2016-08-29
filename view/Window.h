#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../model/MapSprites.h"

#ifndef LIFESIMULATOR_WINDOW_H
#define LIFESIMULATOR_WINDOW_H


class Window : public sf::RenderWindow {

private:
    MapSprites * mapSprites;

    sf::Texture textureGrass;
    sf::Texture textureWater;
    sf::Texture textureSand;

    sf::Sprite spriteGrass;
    sf::Sprite spriteWater;
    sf::Sprite spriteSand;

public:
    Window(sf::VideoMode mode, std::string title);

    void displaySprites();
    void displayAnimals();

    MapSprites *getMapSprites() const {
        return mapSprites;
    }

    void setMapSprites(MapSprites *mapSprites) {
        Window::mapSprites = mapSprites;
    }
};

#endif //LIFESIMULATOR_WINDOW_H
