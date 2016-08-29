#ifndef LIFESIMULATOR_CARNIVORE_H
#define LIFESIMULATOR_CARNIVORE_H

#include "Animal.h"

class Carnivore : public Animal {
public:
    Carnivore();
    Carnivore(int _health, int _speed, int _strength, int _resistance, int _lifeExpectancy);

    void lookForFood();

};


#endif //LIFESIMULATOR_CARNIVORE_H
