#include <iostream>
#include <vector>
#include <algorithm>

#include "MotionSensor.h"

void MotionSensor::addDevice(Observers* observer)  {
    observers.push_back(observer);
}

void MotionSensor::removeDevice(Observers* observer)  {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void MotionSensor::notifyDevices()  {
    for (Observers* observer : observers) {
        observer->update(); // Notify each observer
    }
}

// Simulate detecting motion
void MotionSensor::detectMotion() {
    std::cout << "Motion detected!" << std::endl;
    notifyDevices(); // Notify devices when motion is detected
}
