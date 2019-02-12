#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTreeView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

class TreeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TreeWidget(QWidget *parent = nullptr);
    ~TreeWidget();

private:

    QLineEdit* searchWord;
    QPushButton* searchButton;
    QTreeView* searchTree;
    QPushButton* manageFilesButton;
    QPushButton* tableButton;



signals:

public slots:
};

#endif // TREEWIDGET_H
