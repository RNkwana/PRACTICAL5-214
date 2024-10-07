#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H


#include <string>
using namespace std;

class SmartDevice{
    public:
    virtual string getStatus() =0;
    virtual void performAction()=0;
    virtual string getDeviceType()=0;
    SmartDevice();


 };

 #endif