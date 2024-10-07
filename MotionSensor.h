//CONCRETESUBJECT
#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

#include <vector>

#include "Subject.h"
#include "Observers.h"
class MotionSensor : public Subject {
private: 
    std::vector<Observers*> observers;

public: 
    void addDevice(Observers* observer);
    void removeDevice(Observers* observer);
    void notifyDevices();
    void detectMotion();
    
};
#endif