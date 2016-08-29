#ifndef LIFESIMULATOR_SIMULATOR_H
#define LIFESIMULATOR_SIMULATOR_H

#include <string>
#include "model/species/Animal.h"

class Simulator {

private:
    int updateTime;

public:
    void start();
    void upHungerAndThirst(Animal * animal);
    void stop();
};

#endif //LIFESIMULATOR_SIMULATOR_H
