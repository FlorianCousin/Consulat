#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "filemanagerwidget.h"
#include "treewidget.h"
#include "tablewidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    //Ui::MainWindow *ui;
    const short FILE_MANAGER = 0;
    const short TREE = 1;
    const short TABLE = 2;

    FileManagerWidget* fileManagerWidget;
    TreeWidget* treeWidget;
    TableWidget* tableWidget;
};

#endif // MAINWINDOW_H
