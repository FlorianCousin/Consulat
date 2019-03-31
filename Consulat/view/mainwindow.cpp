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
    if (windowState == FILE_MANAGER) {
        delete mainWidget;
        mainWidget = new FileManagerWidget(this);
        connect(mainWidget, SIGNAL(changeWindowStateSignal(const short &)),this, SLOT(changeWindowStateTo(const short &)));
    } else if (windowState == TREE) {
        delete mainWidget;
        mainWidget = new TreeWidget(data->getTreeModel(), this);
        connect(mainWidget, SIGNAL(changeWindowStateSignal(const short &)), this, SLOT(changeWindowStateTo(const short &)));
        connect(mainWidget, SIGNAL(searchWordSignal(const QString &)), controller, SLOT(searchWord(const QString &)));
    } else if (windowState == TABLE) {
        delete mainWidget;
        mainWidget = new TableWidget(this);
        connect(mainWidget, SIGNAL(changeWindowStateSignal(const short &)), this, SLOT(changeWindowStateTo(const short &)));
    } else {
        throw domain_error("Bad value of windowState (" + to_string(windowState) + ") in MainWindow class");
    }

    setCentralWidget(mainWidget);
}

/**
 * @brief MainWindow::changeWindowStateTo is called when a button to change the
 * window is clicked. It changes the window state according to the button
 * clicked
 *
 * @param newWindowState is the state of the new window to display
 */
void MainWindow::changeWindowStateTo(const short & newWindowState)
{
    windowState = newWindowState;
    update();
}
