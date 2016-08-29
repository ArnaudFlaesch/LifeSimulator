#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include "Simulator.h"
#include "model/species/Vegan.h"
#include "model/species/Cannibal.h"
#include "model/MapSprites.h"
#include "view/Window.h"

void Simulator::start() {
    updateTime = 1.5; // Le simulateur se mettra à jour toutes les 1.5 secondes

    MapSprites * map = new MapSprites();
    map->setMap(map->parseDataFromMapFile("resources/mapLifeSimulator.txt"));

    sf::VideoMode videoMode(map->getSizeX() * map->getSpriteSizeX(), map->getSizeY() * map->getSpriteSizeY());

    Window * simulatorWindow = new Window(videoMode, "LifeSimulator");

    std::vector<Animal *> * animalList = new(std::vector<Animal *>);

    for (int i=0; i<5; i++) {
        animalList->push_back(new Carnivore(100, 1, 10, 5, 30));
        animalList->push_back(new Cannibal(125, 2, 20, 3, 25));
        animalList->push_back(new Vegan(75, 3, 0, 1, 41));
    }

    map->setAnimalsList(animalList);
    simulatorWindow->setMapSprites(map);

    for(std::vector<Animal *>::iterator  it = animalList->begin(); it != animalList->end(); ++it) {
        int positionX = -1, positionY = -1;
        do {
            positionX = rand() % map->getSizeX() +  0;
            positionY = rand() % map->getSizeY() + 0;
        } while(!simulatorWindow->getMapSprites()->checkIsPositionValid(positionX, positionY));
        ((Animal *)*it)->setPositionX(positionX);
        ((Animal *)*it)->setPositionY(positionY);
    }

    simulatorWindow->clear();
    simulatorWindow->displaySprites();

    sf::Clock clock;

    simulatorWindow->displayAnimals();

    std::vector<Animal *> * allAnimals =  simulatorWindow->getMapSprites()->getAnimalsList();
    while (simulatorWindow->isOpen())
    {
        if (clock.getElapsedTime().asSeconds() >= updateTime) {
            clock.restart();
            // Fonctions à implémenter :
            // PathFinding : on cherche l'animal à manger le plus proche
            // Si deux animaux se rencontrent et que l'un commence à manger l'autre, un combat s'engage directement

            std::vector<Animal *>::iterator iterator = allAnimals->begin();
            while (iterator != allAnimals->end()) {
                Animal * animal = ((Animal *)*iterator);

                animal->setPositionX(rand() % (animal->getPositionX()+1 + animal->getPositionX()));
                animal->setPositionY(rand() % (animal->getPositionY()+1 + animal->getPositionY()));

                if (animal->getHunger() >= 30) {
                    //animal->lookForFood(simulatorWindow->getMapSprites());
                }
                else if (animal->getThirst() >= 40) {
                    animal->lookForWater();
                }

                if (animal->getHunger() + 1 >= 100 || animal->getThirst() + 1 == 100 || animal->getAge() + 1 >= animal->getLifeExpectancy()) {
                    iterator = allAnimals->erase(iterator);
                }
                else {
                    upHungerAndThirst(animal);
                    animal->setAge(animal->getAge() + 1);
                    iterator++;
                }
            }

            if (allAnimals->empty()) {
                Simulator::stop();
            }
            simulatorWindow->clear();
            simulatorWindow->displaySprites();
            simulatorWindow->displayAnimals();
        }
        sf::Event event;
        while (simulatorWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                simulatorWindow->close();
        }
        simulatorWindow->display();
    }
}

void Simulator::upHungerAndThirst(Animal * animal) {
    animal->setHunger(animal->getHunger() + 1);
    animal->setThirst(animal->getThirst() + 1);
}

void Simulator::stop() {
    std::cout<<"Fin de la simulation"<<std::endl;
    exit(0);
}