#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Data* data, QWidget *parent) :
    QMainWindow(parent),
    data(data)
{
    fileManagerWidget = new FileManagerWidget(this);
    treeWidget = new TreeWidget(this);
    tableWidget = new TableWidget(this);

    fileManagerWidget->hide();
    treeWidget->hide();

    setCentralWidget(tableWidget);
}

MainWindow::~MainWindow()
{
}

