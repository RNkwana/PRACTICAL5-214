#ifndef DOORLOCK_H
#define DOORLOCK_H

#include <string>
#include "smartDevice.h"
using namespace std;

class DoorLock: public SmartDevice{
    public:
    string getStatus();
    string getDeviceType();
    void performAction();
};

#endif