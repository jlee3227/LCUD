#include "Cube.h"
   
//constructor
Cube::Cube(float side){
    ID = s.getSensorID();
    volume = side*side*side;
}

std::string Cube::to_string(){
    "Type cube with volume: " + getVolume();
}