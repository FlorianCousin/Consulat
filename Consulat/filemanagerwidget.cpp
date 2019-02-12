#include "filemanagerwidget.h"

FileManagerWidget::FileManagerWidget(QWidget *parent) : QWidget(parent)
{
    // Useful widgets initialisation
    listTexts = new QListWidget(this);
    addFileButton = new QPushButton(tr("&Add File"), this);
    processButton = new QPushButton(tr("&Process Files"), this);

    // Spacers initialisation
    QSpacerItem* spacerTop = new QSpacerItem(5, 5);
    QSpacerItem* spacerBottom = new QSpacerItem(5, 5);
    QSpacerItem* spacerLeft = new QSpacerItem(5, 5);
    QSpacerItem* spacerRight = new QSpacerItem(5, 5);

    // Layouts initialisation
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    QVBoxLayout* informationLayout = new QVBoxLayout();
    QHBoxLayout* allLayout = new QHBoxLayout();


    buttonsLayout->addWidget(addFileButton);
    buttonsLayout->addWidget(processButton);

    informationLayout->addSpacerItem(spacerTop);
    informationLayout->addWidget(listTexts);
    informationLayout->addLayout(buttonsLayout);
    informationLayout->addSpacerItem(spacerBottom);

    allLayout->addSpacerItem(spacerLeft);
    allLayout->addLayout(informationLayout);
    allLayout->addSpacerItem(spacerRight);

    this->setLayout(allLayout);
}

FileManagerWidget::~FileManagerWidget()
{
    delete listTexts;
    delete addFileButton;
    delete processButton;
}
