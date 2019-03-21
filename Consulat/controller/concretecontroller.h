#ifndef CONCRETECONTROLLER_H
#define CONCRETECONTROLLER_H

#include "../model/data.h"

class ConcreteController : public Controller
{
public:
    ConcreteController();

private:
    Data* data;
};

#endif // CONCRETECONTROLLER_H
