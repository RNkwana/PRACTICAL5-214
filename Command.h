#ifndef COMMAND_H
#define COMMAND_H
//COMMAND FOR COMP 3

class Command {

public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};


#endif