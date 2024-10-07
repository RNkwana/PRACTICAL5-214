#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "smartDevice.h"
using namespace std;

class ROOM: public SmartDevice{
    public:
    string getStatus();
    string getDeviceType();
    void performAction();
    void addSmartDevice();
    void removeSmartDevice();

    private:
    vector<SmartDevice>* roomDevices;
};

#endif