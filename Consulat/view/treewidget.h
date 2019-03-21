#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTreeView>
#include <QTreeWidget> // TODO chose between QTreeView and QTreeWidget and remove the one not used
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

class TreeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TreeWidget(QWidget *parent = nullptr);
    ~TreeWidget();

    void update();

private:

    QLineEdit* searchWord;
    QPushButton* searchButton;
    //QTreeView* searchTree; TODO
    QTreeWidget* searchTree;
    QPushButton* manageFilesButton;
    QPushButton* tableButton;

    QHBoxLayout* searchLayout;
    QHBoxLayout* buttonsLayout;
    QVBoxLayout* informationLayout;
    QHBoxLayout* allLayout;



signals:
    void changeWindowStateSignal(const short &);

public slots:
    void goToManageFilesWindow();
    void goToTableWindow();
};

#endif // TREEWIDGET_H
