#ifndef LIFESIMULATOR_ANIMAL_H
#define LIFESIMULATOR_ANIMAL_H

#include <string>
#include <vector>

class Animal {
private:
    int age;
    int health, speed, strength;
    int resistance, lifeExpectancy;
    int hunger, thirst;
    int positionX, positionY;
    std::string spritePath;

public:
    Animal();
    Animal(int _health, int _speed, int _strength, int _resistance, int _lifeExpectancy);

    void move();

    virtual void lookForFood() = 0;
    void lookForWater();

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Animal::age = age;
    }

    int getHealth() const {
        return health;
    }

    void setHealth(int health) {
        Animal::health = health;
    }

    int getSpeed() const {
        return speed;
    }

    void setSpeed(int speed) {
        Animal::speed = speed;
    }

    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        Animal::strength = strength;
    }

    int getResistance() const {
        return resistance;
    }

    void setResistance(int resistance) {
        Animal::resistance = resistance;
    }

    int getLifeExpectancy() const {
        return lifeExpectancy;
    }

    void setLifeExpectancy(int lifeExpectancy) {
        Animal::lifeExpectancy = lifeExpectancy;
    }

    int getHunger() const {
        return hunger;
    }

    void setHunger(int hunger) {
        Animal::hunger = hunger;
    }

    int getThirst() const {
        return thirst;
    }

    void setThirst(int thirst) {
        Animal::thirst = thirst;
    }

    int getPositionX() const {
        return positionX;
    }

    void setPositionX(int positionX) {
        Animal::positionX = positionX;
    }

    int getPositionY() const {
        return positionY;
    }

    void setPositionY(int positionY) {
        Animal::positionY = positionY;
    }

    const std::string &getSpritePath() const {
        return spritePath;
    }

    void setSpritePath(const std::string &spritePath) {
        Animal::spritePath = spritePath;
    }
};


#endif //LIFESIMULATOR_ANIMAL_H
