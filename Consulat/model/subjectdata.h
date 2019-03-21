#ifndef SUBJECTDATA_H
#define SUBJECTDATA_H

#include "../view/observer.h"

class SubjectData
{
public:
    SubjectData();
    SubjectData(Observer*);
    ~SubjectData();

    void setObserver(Observer*);
    void notify();

private:
    Observer* observer;
};

#endif // SUBJECTDATA_H
