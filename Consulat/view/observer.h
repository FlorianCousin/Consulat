#ifndef OBSERVER_H
#define OBSERVER_H

#include "../controller/controller.h"

class Observer
{
public:
    Observer(Controller*);
    virtual ~Observer();

    virtual void update() = 0;


protected:
    Controller* controller;
};

#endif // OBSERVER_H
