#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QVBoxLayout>

/**
 * @brief The TableWidget class
 *
 * The widget that is supposed to display the word process in a table
 */
class TableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TableWidget(QWidget *parent = nullptr);
    ~TableWidget();

    void update();


signals:
    void changeWindowStateSignal(const short &) const;

public slots:
    void goToManageFilesWindow() const;
    void goToTreeWindow() const;


private:

    QTableView* table;
    QPushButton* manageFilesButton;
    QPushButton* treeButton;

    QHBoxLayout* buttonsLayout;
    QVBoxLayout* informationLayout;
    QHBoxLayout* allLayout;

};

#endif // TABLEWIDGET_H
