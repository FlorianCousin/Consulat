#include "data.h"

Data::Data()
{
    treeModel = new TreeModel(QString(), QString());
}

Data::~Data()
{
    delete treeModel;
}

/**
 * @brief Data::getTreeModel retrieve the TreeModel
 * @return the TreeModel
 */
QAbstractItemModel *Data::getTreeModel()
{
    return treeModel;
}

/**
 * @brief Data::setTreeModel defines the TreeModel when the data is a string
 * @param searchWord
 * @param dataString
 */
void Data::setTreeModel(const QString searchWord, const QString &dataString)
{
    delete treeModel;
    treeModel = new TreeModel(searchWord, dataString);
    notify();
}

/**
 * @brief Data::setTreeModel defines the TreeModel when the data is a QJsonArray
 * @param searchWord
 * @param dataArray
 */
void Data::setTreeModel(const QString searchWord, const QJsonArray &dataArray)
{
    delete treeModel;
    treeModel = new TreeModel(searchWord, dataArray);
    notify();
}

