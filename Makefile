GPPVERSIONGTEQ48 := $(shell expr `g++ -dumpversion | cut -f1` \>= 4.8)

CPP11 =
ifeq "$(GPPVERSIONGTEQ4)" "1"
    CPP11 = -std=c++11
endif

all: mrproper lifeSimulator clean

lifeSimulator : main.o Animal.o Cannibal.o Carnivore.o Vegan.o MapSprites.o Window.o Simulator.o
	g++ main.o Animal.o Cannibal.o Carnivore.o Vegan.o MapSprites.o Window.o Simulator.o -o lifeSimulator -L SFML-2.4.0/lib -lsfml-window -lsfml-graphics -lsfml-system

main.o : main.cpp
	g++ -c $(CPP11) -Wall main.cpp

Animal.o : model/species/Animal.cpp model/species/Animal.h
	g++ -c $(CPP11) -Wall model/species/Animal.cpp model/species/Animal.h

Cannibal.o : model/species/Cannibal.cpp model/species/Cannibal.h
	g++ -c $(CPP11) -Wall model/species/Cannibal.cpp model/species/Cannibal.h

Carnivore.o : model/species/Carnivore.cpp model/species/Carnivore.h
	g++ -c $(CPP11) -Wall model/species/Carnivore.cpp model/species/Carnivore.h

Vegan.o : model/species/Vegan.cpp model/species/Vegan.h
	g++ -c $(CPP11) -Wall model/species/Vegan.cpp model/species/Vegan.h

MapSprites.o : model/MapSprites.cpp model/MapSprites.h
	g++ -c $(CPP11) -Wall model/MapSprites.cpp model/MapSprites.h

Window.o : view/Window.cpp view/Window.h
	g++ -c $(CPP11) -Wall view/Window.cpp view/Window.h -I SFML-2.4.0/include

Simulator.o : Simulator.cpp Simulator.h
	g++ -c $(CPP11) -Wall Simulator.cpp Simulator.h -I SFML-2.4.0/include

clean :
	find . -name '*.o' -delete
	find . -name '*.gch' -delete

mrproper:
	rm -rf lifeSimulator
