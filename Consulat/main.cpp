#include "view/mainwindow.h"
#include "model/data.h"
#include <QApplication>

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    Data* data = new Data();
    Controller* controller = new Controller();

    QApplication a(argc, argv);

    MainWindow mainWindow(data, controller);

    data->setObserver(&mainWindow);

    mainWindow.show();

    return a.exec();
}
