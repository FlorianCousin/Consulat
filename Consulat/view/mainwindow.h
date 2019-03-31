#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "treewidget.h"
#include "observer.h"
#include "../model/data.h"
#include "../controller/controller.h"

/**
 * @brief The MainWindow class
 *
 * A concrete view of the MVC design
 */
class MainWindow : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    explicit MainWindow(Data*, Controller*, QWidget *parent = nullptr);
    virtual ~MainWindow();

    virtual void update();

private slots:

private:
    TreeWidget* mainWidget;

    Data* data;
};

#endif // MAINWINDOW_H
