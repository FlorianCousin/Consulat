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

void FileManagerWidget::update(const vector<string> &)
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

void FileManagerWidget::goToTreeWindow()
{
    emit changeWindowStateSignal(1);
}
