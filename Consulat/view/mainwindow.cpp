#include "mainwindow.h"

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

/**
 * @brief MainWindow::update updates the window
 */
void MainWindow::update()
{
    delete mainWidget;
    mainWidget = new TreeWidget(data->getTreeModel());

    connect(mainWidget, SIGNAL(generateWordSignal(const QString &)), controller, SLOT(generateWord(const QString &)));
    connect(mainWidget, SIGNAL(searchWordSignal(const QString &)), controller, SLOT(searchWord(const QString &)));

    setCentralWidget(mainWidget);
}
