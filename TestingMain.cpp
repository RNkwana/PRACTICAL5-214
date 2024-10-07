#include <iostream>
#include <vector>
#include <algorithm>

#include "Observers.h"
#include "Subject.h"
#include "MotionSensor.h"
#include "Alarm.h"
#include "Lights.h"
#include "Doors.h"
#include "Command.h"
#include "MacroRoutine.h"
#include "LockDoorCommand.h"
#include "UnLockDoorCommand.h"
#include "OnOffCommand.h"

int main() {
    // Create instances of the sensor and various devices
    MotionSensor motionSensor;
    Lights* livingRoomLight = new Lights(); // Dynamically allocate to use pointers
    Alarm* securityAlarm = new Alarm(); // Dynamically allocate to use pointers
    // Thermostat* smartThermostat = new Thermostat(); // Uncomment if Thermostat class is defined

    std::cout << "===== Test 1: Adding Devices and Triggering Motion =====" << std::endl;
    // Test adding devices to the sensor
    motionSensor.addDevice(livingRoomLight);
    motionSensor.addDevice(securityAlarm);
    // motionSensor.addDevice(smartThermostat); // Uncomment if Thermostat class is defined

    // Trigger motion detection to test all devices being notified
    motionSensor.detectMotion();

    std::cout << "\n===== Test 2: Removing a Device and Triggering Motion Again =====" << std::endl;
    // Test removing one device (Light) from the sensor
    motionSensor.removeDevice(livingRoomLight);

    // Trigger motion detection again to ensure only the remaining devices are notified
    motionSensor.detectMotion();

    std::cout << "\n===== Test 3: Adding a Device Back and Testing Multiple Removals =====" << std::endl;
    // Add the light back to test re-adding
    motionSensor.addDevice(livingRoomLight);
    motionSensor.detectMotion();

    // Remove multiple devices
    motionSensor.removeDevice(securityAlarm);
    // motionSensor.removeDevice(smartThermostat); // Uncomment if Thermostat class is defined
    
    // Trigger motion detection again to ensure only the light reacts
    std::cout << "\nTesting with only the Light device:" << std::endl;
    motionSensor.detectMotion();

    std::cout << "\n===== Test 4: Removing All Devices and Triggering Motion =====" << std::endl;
    // Remove all devices to test no notifications
    motionSensor.removeDevice(livingRoomLight);

    // Trigger motion detection again with no devices registered
    std::cout << "\nTesting with no devices registered:" << std::endl;
    motionSensor.detectMotion();

    std::cout << "\n===== Test 5: Re-Adding Devices and Verifying Multiple Observers =====" << std::endl;
    // Add devices back to the sensor
    motionSensor.addDevice(securityAlarm);
    // motionSensor.addDevice(smartThermostat); // Uncomment if Thermostat class is defined
    motionSensor.addDevice(livingRoomLight);

    // Trigger motion detection with all devices back
    std::cout << "\nTesting with all devices re-added:" << std::endl;
    motionSensor.detectMotion();

    // Create receiver objects (Lights and Doors)
    Lights* livingRoomLight2 = new Lights(); // Dynamically allocate to use pointers
    Doors* frontDoor = new Doors(); // Dynamically allocate to use pointers

    // Create command objects as pointers
    OnOffCommand* turnOnLightCommand = new OnOffCommand(true, livingRoomLight2);   // Command to turn the light on
    OnOffCommand* turnOffLightCommand = new OnOffCommand(false, livingRoomLight2); // Command to turn the light off
    LockDoorCommand* lockFrontDoorCommand = new LockDoorCommand(frontDoor);          // Command to lock the front door
    UnLockDoorCommand* unlockFrontDoorCommand = new UnLockDoorCommand(frontDoor);      // Command to unlock the front door

    // Testing individual commands
    std::cout << "===== Test 6: Turning Light On and Off =====" << std::endl;
    std::cout << "Turning light ON:" << std::endl;
    turnOnLightCommand->execute();
    std::cout << "Light status: " << (turnOnLightCommand->getStatus() ? "On" : "Off") << std::endl;
    std::cout << "Turning light OFF:" << std::endl;
    turnOffLightCommand->execute();
    std::cout << "Light status: " << (turnOffLightCommand->getStatus() ? "On" : "Off") << "\n" << std::endl;

    std::cout << "===== Test 7: Locking and Unlocking the Door =====" << std::endl;
    std::cout << "Locking the front door:" << std::endl;
    lockFrontDoorCommand->execute();
    std::cout << "Unlocking the front door:" << std::endl;
    unlockFrontDoorCommand->execute();
    std::cout << std::endl;

    // Create MacroRoutine object and add procedures
    MacroRoutine eveningRoutine;
    eveningRoutine.addProcedures(turnOffLightCommand);
    eveningRoutine.addProcedures(lockFrontDoorCommand);

    std::cout << "===== Test 8: Executing MacroRoutine (Evening Routine) =====" << std::endl;
    std::cout << "Executing Evening Routine (turn off light and lock door):" << std::endl;
    eveningRoutine.execute();
    std::cout << std::endl;

    // Test adding and removing procedures in MacroRoutine
    std::cout << "===== Test 9: Modifying MacroRoutine =====" << std::endl;
    std::cout << "Adding turnOnLightCommand to the evening routine:" << std::endl;
    eveningRoutine.addProcedures(turnOnLightCommand);

    std::cout << "Executing Modified Evening Routine (turn on light, turn off light, and lock door):" << std::endl;
    eveningRoutine.execute();
    std::cout << std::endl;

    std::cout << "Removing turnOnLightCommand from the evening routine:" << std::endl;
    eveningRoutine.removeProcedures(turnOnLightCommand);
    std::cout << "Executing Modified Evening Routine (turn off light and lock door):" << std::endl;
    eveningRoutine.execute();
    std::cout << std::endl;

    return 0;
}