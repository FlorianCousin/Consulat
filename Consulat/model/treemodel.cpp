#include "treemodel.h"

#include <iostream> // TODO remove this at the end

TreeModel::TreeModel(const QString &searchWord, const QString &stringData, QObject *parent) :
    QAbstractItemModel(parent),
    rootItem(new TreeItem(searchWord, nullptr))
{
    setUpModelData(stringData);
}

TreeModel::TreeModel(const QString &searchWord, const QJsonArray &arrayData, QObject *parent) :
    QAbstractItemModel(parent),
    rootItem(new TreeItem(searchWord, nullptr))
{
    setUpModelData(arrayData);
}

TreeModel::~TreeModel()
{
    delete rootItem;
}

/**
 * @brief TreeModel::index overrides QAbstractItemModel::index
 * @param row
 * @param column
 * @param parent
 * @return the index of the item in the model specified by the given row,
 * column and parent index.
 */
QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    // When reimplementing this function in a subclass, call createIndex() to generate model indexes that other components can use to refer to items in your model.

    TreeItem * parentItem;
    if (parent.isValid())
        parentItem = static_cast<TreeItem*>(parent.internalPointer());
    else
        parentItem = rootItem;

    TreeItem * childItem;
    try {
        childItem = parentItem->getChild(row);
    } catch (std::out_of_range) {
        return QModelIndex();
    }

    return createIndex(row, column, childItem);
}

/**
 * @brief TreeModel::parent overrides QAbstractItemModel::parent
 * @param index
 * @return the parent of the model item with the given index. If the item has
 * no parent, an invalid QModelIndex is returned.
 */
QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    // A common convention used in models that expose tree data structures is that only items in the first column have children.
    // For that case, when reimplementing this function in a subclass the column of the returned QModelIndex would be 0.
    // When reimplementing this function in a subclass, be careful to avoid calling QModelIndex member functions,
    // such as QModelIndex::parent(), since indexes belonging to your model will simply call your implementation, leading to infinite recursion.

    if (!index.isValid())
        return QModelIndex();

    TreeItem * indexItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem * parentItem = indexItem->getParent();

    if (parentItem == rootItem)
        return QModelIndex();

    if (parentItem)
        return createIndex(parentItem->getRow(), 0, parentItem);
    else
        return QModelIndex();
}

/**
 * @brief TreeModel::rowCount overrides QAbstractItemModel::rowCount
 * @param parent
 * @return the number of rows under the given parent. When the parent is valid
 * it means that rowCount is returning the number of children of parent.
 */
int TreeModel::rowCount(const QModelIndex &parent) const
{
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        return rootItem->getChildCount();

    return static_cast<TreeItem*>(parent.internalPointer())->getChildCount();
}

/**
 * @brief TreeModel::columnCount overrides QAbstractItemModel::columnCount
 * @param parent
 * @return the number of columns for the children of the given parent.
 */
int TreeModel::columnCount(const QModelIndex &parent) const
{
    // In most subclasses, the number of columns is independent of the parent.

    if (!parent.isValid())
        return rootItem->getColumnCount();

    return static_cast<TreeItem*>(parent.internalPointer())->getColumnCount();
}

/**
 * @brief TreeModel::data overrides QAbstractitemMoel::data
 * @param index
 * @param role
 * @return the data stored under the given role for the item referred to by the
 * index.
 */
QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    // If you do not have a value to return, return an invalid QVariant instead of returning 0.

    if (!index.isValid() or role != Qt::DisplayRole)
        return QVariant();

    return static_cast<TreeItem*>(index.internalPointer())->
            getData(index.column());
}

/**
 * @brief TreeModel::flags ensures that the model is read-only
 * @param index
 * @return the item flags for the given index.
 */
Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return nullptr;

    return QAbstractItemModel::flags(index);
}

/**
 * @brief TreeModel::headerData
 * @param section
 * @param orientation
 * @param role
 * @return the data for the given role and section in the header with the
 * specified orientation.
 */
QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->getData(section);

    return QVariant();
}

void TreeModel::setUpModelData(const QString & stringData)
{
    QString tmpString(stringData.trimmed());
    QList<TreeItem*> parents;
    parents << rootItem;
    TreeItem * tmpItem;
    QString tmpItemData;
    int position = 1;
    int len = stringData.size();
    int earliestB;

    tmpString.remove(0, 1); // Remove the first open bracket
    tmpString.remove(len - 1, 1); // remove the last closed bracket

    int openB = stringData.indexOf('[', 1);
    if (openB == -1) openB = len;
    int closeB = stringData.indexOf(']', 1);
    if (closeB == -1) closeB = len;

    while (position < len) {
        earliestB = std::min(openB, closeB);

        if (stringData[earliestB] == '[') {
            if (earliestB - position == 0) {
                std::cerr << "There should not be two open brackets that"
                             "follows, see the web part" << std::endl;
            }

            tmpItemData = stringData.mid(position, earliestB - position);
            if (tmpItemData != ',') {
                tmpItemData = tmpItemData.replace(',', ' ').remove('"');
                tmpItem = new TreeItem(tmpItemData, parents.last());
                parents.last()->appendChild(tmpItem);
                parents << tmpItem;
            }

            position = earliestB + 1;
            openB = stringData.indexOf('[', position);
            if (openB == -1) openB = len;
        }

        else if (stringData[earliestB] == ']'){
            if (earliestB - position > 0) {
                tmpItemData = stringData.mid(position, earliestB - position).replace(',', ' ').remove('"');
                tmpItem = new TreeItem(tmpItemData, parents.last());
                parents.last()->appendChild(tmpItem);
            }
            else
                parents.pop_back();

            position = earliestB + 1;
            closeB = stringData.indexOf(']', position);
            if (closeB == -1) closeB = len;
        }
    }
}

void TreeModel::setUpModelData(const QJsonArray &jsonArray, TreeItem *parent)
{
    if (jsonArray.empty())
        std::cerr << "The json array should not be empty" << std::endl;

    if (jsonArray.size() == 1 && jsonArray[0].type() == 4) {
        setUpModelData(jsonArray[0].toArray(), parent);
        return;
    }

    if (!parent)
        parent = rootItem;


    QString branchRootData;
    QList<TreeItem*> children;
    TreeItem * child = nullptr;

    QJsonArray::const_iterator it = jsonArray.constBegin();

    if ((it)->type() == 3) {
        branchRootData.append(it->toString());
        it++;

        while (it->type() == 3) {
            branchRootData.append(" " + it->toString());
            it++;
        }

        child = new TreeItem(branchRootData, parent);
        parent->appendChild(child);
    }
    else
        child = parent;



    while (it != jsonArray.constEnd()) {
        setUpModelData(it->toArray(), child);
        it++;
    }
}
