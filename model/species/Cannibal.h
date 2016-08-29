#ifndef LIFESIMULATOR_CANNIBAL_H
#define LIFESIMULATOR_CANNIBAL_H

#include "Carnivore.h"

class Cannibal : public Carnivore {
public :
    Cannibal(int _health, int _speed, int _strength, int _resistance, int _lifeExpectancy);

    void lookForFood();
};


#endif //LIFESIMULATOR_CANNIBAL_H
