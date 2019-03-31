#include "treeitem.h"

#include <iostream> // TODO remove this at the end

TreeItem::TreeItem(const QString& data, TreeItem *parentItem) :
    data(data),
    parent(parentItem)
{

}

TreeItem::~TreeItem()
{
    qDeleteAll(children);
}

/**
 * @brief TreeItem::appendChild appends a child to this node
 * @param child the TreeItem to append as a child
 */
void TreeItem::appendChild(TreeItem *child)
{
    children.append(child);
}

/**
 * @brief TreeItem::getChild retreives a child to this node
 * @param row the row number fo the child to retreive
 * @return the requested child
 */
TreeItem *TreeItem::getChild(int row)
{
    if (row < 0 || row >= getChildCount())
        throw std::out_of_range("The row (" + std::to_string(row)
                                + ") is out of range [[" + std::to_string(0)
                                + ", " + std::to_string(getChildCount())
                                + "]].");

    return children.at(row);
}

/**
 * @brief TreeItem::getChildCount gets the number of children
 * @return the number of children
 */
int TreeItem::getChildCount() const
{
    return children.count();
}

/**
 * @brief TreeItem::getColumnCount gets the number of columns
 * @return the number of columns
 */
int TreeItem::getColumnCount() const
{
    // return data.count(); This is when data is a QList
    return 1;
}


/**
 * @brief TreeItem::getData gets the data of this node
 * @param column the number of the column to go and catch the data
 * @return the requested data
 */
QString TreeItem::getData(int column) const
{
    if (column < 0 || column >= getColumnCount())
        throw std::out_of_range("The row (" + std::to_string(column)
                                + ") is out of range [[" + std::to_string(0)
                                + ", " + std::to_string(getColumnCount())
                                + "]].");

    //return data.at(column); This is when data is a QList
    return data;
}

/**
 * @brief TreeItem::getData gets the data of this node
 * @return the data of this node as a QString
 */
QString TreeItem::getData() const {
    return data;
}

/**
 * @brief TreeItem::getRow gets the row of this node in its parent
 * @return the row of this node, 0 if it is a root
 */
int TreeItem::getRow() const
{
    if (parent)
        return parent->children.indexOf(const_cast<TreeItem*>(this));

    return 0;
}

/**
 * @brief TreeItem::getParent gets the parent of this node
 * @return the parent of this node
 */
TreeItem *TreeItem::getParent()
{
    return parent;
}
