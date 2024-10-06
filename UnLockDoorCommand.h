#ifndef UNLOCKDOORCOMMAND_H
#define UNLOCKDOORCOMMAND_H

#include "Command.h"
#include "Doors.h"
class UnLockDoorCommand : public Command{
private:
    Doors* door;
public:
    UnLockDoorCommand(Doors* d);
    void execute();

};
#endif