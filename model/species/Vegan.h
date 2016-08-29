#ifndef LIFESIMULATOR_VEGAN_H
#define LIFESIMULATOR_VEGAN_H

#include "Animal.h"

class Vegan : public Animal {
public:
    Vegan(int _health, int _speed, int _strength, int _resistance, int _lifeExpectancy);

    void lookForFood();

};


#endif //LIFESIMULATOR_VEGAN_H
