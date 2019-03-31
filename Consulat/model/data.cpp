#include "data.h"

#include <iostream> // TODO remove this at the end

Data::Data()
{
    treeModel = new TreeModel(QString(), QString());
}

Data::~Data()
{
    delete treeModel;
}

void Data::addFile(const string &fileName)
{
    fileNames.push_back(fileName);
    notify();
}

void Data::removeFile(const int &fileNumber)
{
    fileNames.removeAt(fileNumber);
    notify();
}

const QList<string> &Data::getFileNames() const
{
    return fileNames;
}

QAbstractItemModel *Data::getTreeModel()
{
    return treeModel;
}

void Data::setTreeModel(const QString searchWord, const QString &dataString)
{
    delete treeModel;
    treeModel = new TreeModel(searchWord, dataString);
    notify();
}

void Data::setTreeModel(const QString searchWord, const QJsonArray &dataArray)
{
    delete treeModel;
    treeModel = new TreeModel(searchWord, dataArray);
    notify();
}

