#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include <string>
#include "smartDevice.h"
using namespace std;

class Thermostat: public SmartDevice{
    public:
    string getStatus();
    string getDeviceType();
    void performAction();
};

#endif