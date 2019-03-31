#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>

#include <QJsonArray>

#include "treeitem.h"

/**
 * @brief The TreeModel class
 *
 * The concrete tree implementation of an abstract model
 */
class TreeModel : public QAbstractItemModel
{
public:
    explicit TreeModel(const QString & searchWord, const QString & stringData = QString(), QObject * parent = nullptr);
    explicit TreeModel(const QString & searchWord, const QJsonArray & arrayData = QJsonArray(), QObject * parent = nullptr);
    ~TreeModel() override;

    // Mandatory overriding
    virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    virtual QModelIndex parent(const QModelIndex &index) const override;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Copy pasting of https://doc.qt.io/qt-5/qtwidgets-itemviews-simpletreemodel-example.html
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;


private:
    void setUpModelData(const QString & stringData);
    void setUpModelData(const QJsonArray & jsonArray, TreeItem * parent = nullptr);

    TreeItem* rootItem;
};

#endif // TREEMODEL_H
