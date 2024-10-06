#include <iostream>
#include "LockDoorCommand.h"

LockDoorCommand::LockDoorCommand(Doors* d){
    this->door = d;
}

void LockDoorCommand::execute(){
    door->lock();
}