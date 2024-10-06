#ifndef MACROROUTINE_H
#define MACROROUTINE_H
#include <vector>
//INVOKER   
#include "Command.h";
class MacroRoutine  {
private:
    std::vector<Command*> commands;
public:
    ~MacroRoutine();
    void addProcedures(Command* command);
    void removeProcedures(Command* command);
    void execute();

};
#endif