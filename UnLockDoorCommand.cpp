#include <iostream>
#include "UnLockDoorCommand.h"

UnLockDoorCommand::UnLockDoorCommand(Doors* d){
    this->door = d;
}

void UnLockDoorCommand::execute(){
    door->unlock();
}