#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTreeView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

/**
 * @brief The TreeWidget class
 *
 * The widget that is supposed to display the word process in a tree
 */
class TreeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TreeWidget(QAbstractItemModel * treeModel, QWidget *parent = nullptr);
    ~TreeWidget();

    void update(QAbstractItemModel * treeModel);


signals:
    void generateWordSignal(const QString &) const;
    void searchWordSignal(const QString &) const;

public slots:
    void generateButtonClicked() const;
    void searchButtonClicked() const;



private:

    QLineEdit* searchWord;
    QPushButton* generateButton;
    QPushButton* searchButton;
    QTreeView* searchTree;

    QHBoxLayout* buttonsLayout;
    QVBoxLayout* informationLayout;
    QHBoxLayout* allLayout;

};

#endif // TREEWIDGET_H
