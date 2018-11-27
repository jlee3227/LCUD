#include "Cylinder.h"
   
//constructor
Cylinder::Cylinder(int radius, int heigth){
    Cradius = radius;
    Cheigth = heigth;
    MaxVolume = 2*3.14*radius*heigth;
    ShapeID = "Cylinder";
}

//get dimensions
float_t Cylinder::getRadius(){
    return Cradius;
}

float Cylinder::getHeight(){
    return Cheigth;
}


std::string Cylinder::to_string(){
    return "Type Cylinder with volume: " + std::to_string(MaxVolume);
}
