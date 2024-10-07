#include <iostream>
#include "MacroRoutine.h"
#include <vector>
#include <algorithm>

MacroRoutine::~MacroRoutine(){
    for(Command* command : commands){
        delete command;
        command = nullptr;
    } 
}

void MacroRoutine::addProcedures(Command* command){
    commands.push_back(command);
}

void MacroRoutine::removeProcedures(Command* command) {
 // Use a lambda to ensure correct pointer comparison
        commands.erase(std::remove_if(commands.begin(), commands.end(),
            [command](Command* cmd) { return cmd == command; }), commands.end());

}

void MacroRoutine::execute(){
    for(Command* command: commands){
        command->execute();
    }
}