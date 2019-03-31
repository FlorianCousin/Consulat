#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "filemanagerwidget.h"
#include "treewidget.h"
#include "tablewidget.h"
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
    void changeWindowStateTo(const short & newWindowState);

private:
    const short FILE_MANAGER = 0;
    const short TREE = 1;
    const short TABLE = 2;

    short windowState = 1;


    QWidget* mainWidget;

    Data* data;
};

#endif // MAINWINDOW_H