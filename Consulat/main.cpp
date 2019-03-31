#include "view/mainwindow.h"
#include "model/data.h"
#include "controller/concretecontroller.h"

#include <QApplication>

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    Data* data = new Data();
    Controller* controller = new ConcreteController(data);

    QApplication a(argc, argv);

    MainWindow mainWindow(data, controller);

    data->setObserver(&mainWindow);

    mainWindow.show();

    return a.exec();
}
