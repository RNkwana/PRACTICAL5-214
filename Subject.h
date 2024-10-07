#ifndef SUBJECT_H
#define SUBJECT_H
#include "Observers.h"

class Subject {
public: 
    virtual void addDevice(Observers* observer) = 0;
    virtual void removeDevice(Observers* observer) = 0;
    virtual void notifyDevices() = 0;
    virtual ~Subject(){};
};
#endif