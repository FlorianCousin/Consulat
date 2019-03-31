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

/**
 * @brief SubjectData::setObserver sets an object as observer of this data
 *
 * @param observer the object that has to observe this data
 */
void SubjectData::setObserver(Observer * observer)
{
    this->observer = observer;
}

/**
 * @brief SubjectData::notify makes the observer know that this data has
 * changed and make it update
 */
void SubjectData::notify() const
{
    observer->update();
}
