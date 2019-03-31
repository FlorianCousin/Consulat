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

/**
 * @brief The FileManagerWidget class
 *
 * The widget that is supposed to manage the files associated with the process
 * of words.
 */
class FileManagerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FileManagerWidget(QWidget *parent = nullptr);
    ~FileManagerWidget();

    void update(const vector<string> & fileNames);


signals:
    void changeWindowStateSignal(const short &) const;

private slots:
    void goToTreeWindow() const;


private:

    QListWidget* listTexts;
    QPushButton* addFileButton;
    QPushButton* processButton;

    QHBoxLayout* buttonsLayout;
    QVBoxLayout* informationLayout;
    QHBoxLayout* allLayout;
};

#endif // FILEMANAGERWIDGET_H
