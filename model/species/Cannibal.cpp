#include <iostream>
#include "Cannibal.h"
#include "../../Simulator.h"

Cannibal::Cannibal(int _health, int _speed, int _strength, int _resistance, int _lifeExpectancy) :
Carnivore(_health, _speed, _strength, _resistance, _lifeExpectancy) {
    setSpritePath("resources/sprites/pikachu.png");
}

void Cannibal::lookForFood() {

}
