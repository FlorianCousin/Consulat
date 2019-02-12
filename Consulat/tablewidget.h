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

private:

    QTableView* table;
    QPushButton* manageFilesButton;
    QPushButton* treeButton;


signals:

public slots:
};

#endif // TABLEWIDGET_H
