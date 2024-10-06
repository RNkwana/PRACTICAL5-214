#ifndef LIGHTS_H
#define LIGHTS_H
//ConcreteObserver

#include "Observers.h"
class Lights : public Observers{

public: 
    void turnon();
    void turnoff();
    void update();

};
#endif