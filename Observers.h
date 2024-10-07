#ifndef OBSERVERS_H
#define OBSERVERS_H

class Observers {

public: 
    virtual void update() = 0;
    virtual ~Observers() = default;
};
#endif