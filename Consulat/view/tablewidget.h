#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QVBoxLayout>

class TableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TableWidget(QWidget *parent = nullptr);
    ~TableWidget();

    void update();

private:

    QTableView* table;
    QPushButton* manageFilesButton;
    QPushButton* treeButton;

    QHBoxLayout* buttonsLayout;
    QVBoxLayout* informationLayout;
    QHBoxLayout* allLayout;


signals:
    void changeWindowStateSignal(const short &);

public slots:
    void goToManageFilesWindow();
    void goToTreeWindow();
};

#endif // TABLEWIDGET_H
