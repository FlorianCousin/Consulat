#ifndef FILEMANAGERWIDGET_H
#define FILEMANAGERWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <vector>
#include <string>

using namespace std;

class FileManagerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FileManagerWidget(QWidget *parent = nullptr);
    ~FileManagerWidget();

    void update(const vector<string>&);

private:

    QListWidget* listTexts;
    QPushButton* addFileButton;
    QPushButton* processButton;

    QHBoxLayout* buttonsLayout;
    QVBoxLayout* informationLayout;
    QHBoxLayout* allLayout;


signals:
    void changeWindowStateSignal(const short &);

private slots:
    void goToTreeWindow();
};

#endif // FILEMANAGERWIDGET_H
