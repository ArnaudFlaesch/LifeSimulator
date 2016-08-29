cmake_minimum_required(VERSION 2.5)
project(LifeSimulator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SFML_ROOT "SFML-2.4.0")
set(SOURCE_FILES main.cpp model/MapSprites.cpp model/MapSprites.h view/Window.cpp view/Window.h model/species/Animal.cpp model/species/Animal.h model/species/Vegan.cpp model/species/Vegan.h model/species/Carnivore.cpp model/species/Carnivore.h model/species/Cannibal.cpp model/species/Cannibal.h Simulator.cpp Simulator.h)
set(EXECUTABLE_NAME "LifeSimulator")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/SFML-2.4.0/share/SFML/cmake/Modules")
file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})

find_package (SFML 2 REQUIRED COMPONENTS graphics window system)
if(SFML_FOUND)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(LifeSimulator ${SFML_LIBRARIES})
endif()
