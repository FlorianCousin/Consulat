#include "observer.h"

Observer::Observer(Controller * controller):
    controller(controller)
{

}

Observer::~Observer()
{
    delete controller;
}
