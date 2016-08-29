#include <iostream>
#include "Vegan.h"
#include "../../Simulator.h"

Vegan::Vegan(int _health, int _speed, int _strength, int _resistance, int _lifeExpectancy) :
        Animal(_health, _speed, _strength, _resistance, _lifeExpectancy) {
    setSpritePath("resources/sprites/charizard.png");
}

void Vegan::lookForFood() {

}