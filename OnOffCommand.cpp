#include <iostream>
#include "OnOffCommand.h"

OnOffCommand::OnOffCommand(bool s, Lights* l){
    this->light = l;
    this->on = s;
}

void OnOffCommand::execute(){
    if(on){
        light->turnon();
    } else {
        light->turnoff();
    }
}

bool OnOffCommand::getStatus(){
    return this->on;
}