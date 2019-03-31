#ifndef SUBJECTDATA_H
#define SUBJECTDATA_H

#include "../view/observer.h"

/**
 * @brief The SubjectData class
 *
 * The abstract model of the MVC design.
 */
class SubjectData
{
public:
    SubjectData();
    explicit SubjectData(Observer*);
    ~SubjectData();

    void setObserver(Observer*);
    void notify() const;

private:
    Observer* observer;
};

#endif // SUBJECTDATA_H
