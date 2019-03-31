#include "filemanagerwidget.h"

#include <iostream> // TODO remove this at the end

FileManagerWidget::FileManagerWidget(QWidget *parent) : QWidget(parent)
{
    // Useful widgets initialisation
    listTexts = new QListWidget(this);
    addFileButton = new QPushButton(tr("&Add File"), this);
    processButton = new QPushButton(tr("&Process Files"), this);

    buttonsLayout = new QHBoxLayout();
    informationLayout = new QVBoxLayout();
    allLayout = new QHBoxLayout();

    connect(processButton, SIGNAL(clicked()), this, SLOT(goToTreeWindow()));

    update(vector<string>());
}

FileManagerWidget::~FileManagerWidget()
{
    delete listTexts;
    delete addFileButton;
    delete processButton;

    delete buttonsLayout;
    delete informationLayout;
    delete allLayout;
}

/**
 * @brief FileManagerWidget::update updates the window according to the list of
 * the names of the files that has to be considered in the word process
 *
 * @param fileNames the vector of the names of the files
 */
void FileManagerWidget::update(const vector<string> & fileNames)
{
    buttonsLayout->addWidget(addFileButton);
    buttonsLayout->addWidget(processButton);

    informationLayout->addSpacing(5);
    informationLayout->addWidget(listTexts);
    informationLayout->addLayout(buttonsLayout);
    informationLayout->addSpacing(5);

    allLayout->addSpacing(5);
    allLayout->addLayout(informationLayout);
    allLayout->addSpacing(5);

    this->setLayout(allLayout);
}

/**
 * @brief FileManagerWidget::goToTreeWindow is called when the button to go to
 * the tree window is clicked. It emits a signal the MainWindow instance is
 * waiting for.
 */
void FileManagerWidget::goToTreeWindow() const
{
    emit changeWindowStateSignal(1);
}
