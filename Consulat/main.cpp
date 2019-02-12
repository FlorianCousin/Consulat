#include "mainwindow.h"
#include "data.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Data* model = new Data();

    QApplication a(argc, argv);
    MainWindow w(model);

    w.show();

    return a.exec();
}
