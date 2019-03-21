#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream> // TODO remove this at the end

MainWindow::MainWindow(Data* data, Controller* controller, QWidget *parent) :
    QMainWindow(parent),
    Observer(controller),
    mainWidget(nullptr),
    data(data)
{
    update();
}

MainWindow::~MainWindow()
{
    delete mainWidget;

    delete data;
}

void MainWindow::update()
{
    if (windowState == FILE_MANAGER) {
        delete mainWidget;
        mainWidget = new FileManagerWidget(this);
        connect(mainWidget, SIGNAL(changeWindowStateSignal(const short &)), this, SLOT(changeWindowStateTo(const short &)));
    } else if (windowState == TREE) {
        delete mainWidget;
        mainWidget = new TreeWidget(this);
        connect(mainWidget, SIGNAL(changeWindowStateSignal(const short &)), this, SLOT(changeWindowStateTo(const short &)));
    } else if (windowState == TABLE) {
        delete mainWidget;
        mainWidget = new TableWidget(this);
        connect(mainWidget, SIGNAL(changeWindowStateSignal(const short &)), this, SLOT(changeWindowStateTo(const short &)));
    } else {
        throw domain_error("Bad value of windowState (" + to_string(windowState) + ") in MainWindow class");
    }

    setCentralWidget(mainWidget);
}

void MainWindow::changeWindowStateTo(const short & newWindowState)
{
    windowState = newWindowState;
    update();
}

