#ifndef OBSERVER_H
#define OBSERVER_H

#include "../controller/controller.h"

/**
 * @brief The Observer class
 *
 * The abstract view of the MVC design
 */
class Observer
{
public:
    explicit Observer(Controller*);
    virtual ~Observer();

    virtual void update() = 0;


protected:
    Controller* controller;
};

#endif // OBSERVER_H
