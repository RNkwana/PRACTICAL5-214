#ifndef ONOFFCOMMAND_H
#define ONOFCOMMAND_H

//for lights
#include "Command.h"
#include "Lights.h"
class OnOffCommand : public Command {
private:
    bool on;
    Lights* light;

public: 
    OnOffCommand(bool s, Lights* l);
    void execute();
    bool getStatus();//Thati

};
#endif