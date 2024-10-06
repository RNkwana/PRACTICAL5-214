#ifndef LOCKDOORCOMMAND_H
#define LOCKDOORCOMMAND_H

#include "Command.h"
#include "Doors.h"
class LockDoorCommand : public Command {

private:
    Doors* door;
public:
    LockDoorCommand(Doors* d);
    void execute();

};
#endif