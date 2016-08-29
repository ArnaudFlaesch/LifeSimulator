#include <iostream>
#include "Carnivore.h"
#include "../../Simulator.h"

Carnivore::Carnivore() { }

Carnivore::Carnivore(int _health, int _speed, int _strength, int _resistance, int _lifeExpectancy) :
Animal(_health, _speed, _strength, _resistance, _lifeExpectancy) {
    setSpritePath("resources/sprites/doge.png");
}

void Carnivore::lookForFood() {

}