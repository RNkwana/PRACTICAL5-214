#ifndef LIGHT_H
#define LIGHT_H

#include <string>
#include "smartDevice.h"
using namespace std;

class Light: public SmartDevice{
    public:
    string getStatus();
    string getDeviceType();
    void performAction();
};

#endif