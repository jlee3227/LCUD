/**
 * @brief Sensors class methods
 * 
 * @details
 *          This file implements the Sensors class member methods;
 *          It consists of the constructor, the destructor, the update function,
 *          and a toString method
 *
 * 
 * @author Vance Gullberg
 * @author Marco Manuel
 * @author Morgan O'Brien
 */
#include "Sensors.h"
   
/**
 * @brief Sensors constructor
 * 
 * @details
 *          
 *
 * @param
 * @return
 * @author Vance Gullberg
 */
Sensors::Sensors(){
	int ID = 0;                       //sensorID;
    SensorID = std::to_string(ID);    //convert int to string
    file = "/dev/ttyACM" + SensorID;  //setting file attribute to directory
}

//destructor
Sensors::~Sensors(){
}


void Sensors::update(){
    std::ifstream inFile;
    inFile.open(file);
    //if threres a line, read it and split
    std::string line;
    if (getline(inFile, line)){
        //std::cout << "Hello from Sensors::update()" << std::endl; //remove me!
        std::stringstream ss(line);
        std::string duration;
        getline(ss,duration, ' ');
        std::string temperature;
        getline(ss,temperature,' ');

        //if there is data, set attributes accordingly
        if(!duration.empty() && !temperature.empty()){
            SDuration = stof(duration);
            STemperature = stof(temperature);
        }
        //std::cout << duration + '\t' + temperature << std::endl; //remove me!
    }
    inFile.close();
}

//tostring
std::string Sensors::to_string(){
    return "Sensor number "+SensorID+" currently has duration "+std::to_string(SDuration)+" and temperature "+std::to_string(STemperature);
}