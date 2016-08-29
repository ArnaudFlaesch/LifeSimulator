#include "Animal.h"

Animal::Animal() { }

Animal::Animal(int _health, int _speed, int _strength, int _resistance, int _lifeExpectancy) {
    health = _health;
    speed = _speed;
    strength = _strength;
    resistance = _resistance;
    lifeExpectancy = _lifeExpectancy;
    hunger = 0;
    thirst = 0;
    age = 0;
}

void Animal::lookForWater() {

}