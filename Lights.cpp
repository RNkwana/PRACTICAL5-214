#include <iostream>
#include "Lights.h"

void Lights::turnon(){
    std::cout << "Light is turned on." << std::endl;
}

void Lights::turnoff(){
    std::cout << "Light is turned off." << std::endl;
}

void Lights::update(){
    std::cout << "Light is turned on due to motion detected!" << std::endl;
}