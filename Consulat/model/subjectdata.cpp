#include "subjectdata.h"

SubjectData::SubjectData()
{

}

SubjectData::SubjectData(Observer * observer):
    observer(observer)
{

}

SubjectData::~SubjectData()
{

}

void SubjectData::setObserver(Observer * observer)
{
    this->observer = observer;
}

void SubjectData::notify()
{
    observer->update();
}
