#include <iostream>
#include "OnOffCommand.h"

OnOffCommand::OnOffCommand(bool s, Lights* l){
    this->light = l;
    this->on = s;
}

void OnOffCommand::execute(){
    if(on){
        light->turnoff();
    } else {
        light->turnon();
    }
}

bool OnOffCommand::getStatus(){
    return this->on;
}