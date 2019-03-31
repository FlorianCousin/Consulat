#ifndef TREEITEM_H
#define TREEITEM_H

#include <QObject>

class TreeItem
{
public:
    explicit TreeItem(const QString &data, TreeItem *parentItem);
    ~TreeItem();

    void appendChild(TreeItem * child);

    TreeItem *getChild(int row);
    int getChildCount() const;
    int getColumnCount() const;
    QString getData(int column) const;
    QString getData() const;
    int getRow() const;
    TreeItem *getParent();

private:
    QList<TreeItem*> children;
    QString data;
    TreeItem * parent;
};

#endif // TREEITEM_H
