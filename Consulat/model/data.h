#ifndef MODEL_H
#define MODEL_H

#include <string>

#include "subjectdata.h"
#include "treemodel.h"

using namespace std;

/**
 * @brief The Data class
 *
 * The concrete model of the MVC design.
 */
class Data: public SubjectData
{
public:
    Data();
    ~Data();

    void addFile(const string &);
    void removeFile(const int &);
    const QList<string>& getFileNames() const;
    QAbstractItemModel * getTreeModel();
    void setTreeModel(const QString searchWord, const QString & dataString);
    void setTreeModel(const QString searchWord, const QJsonArray & dataArray);

private:
    QList<string> fileNames;
    QAbstractItemModel * treeModel;
};

#endif // MODEL_H
