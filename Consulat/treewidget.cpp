#include "treewidget.h"

TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent)
{
    // Useful widgets initialisation
    searchWord = new QLineEdit(this);
    searchButton = new QPushButton(tr("&Search"), this);
    searchTree = new QTreeView(this);
    manageFilesButton = new QPushButton(tr("&Manage Files"), this);
    tableButton = new QPushButton(tr("&Table"), this);

    // Spacers initialisation
    QSpacerItem* spacerTop = new QSpacerItem(5, 5);
    QSpacerItem* spacerBottom = new QSpacerItem(5, 5);
    QSpacerItem* spacerLeft = new QSpacerItem(5, 5);
    QSpacerItem* spacerRight = new QSpacerItem(5, 5);

    // Layouts initialisation
    QHBoxLayout* searchLayout = new QHBoxLayout();
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    QVBoxLayout* informationLayout = new QVBoxLayout();
    QHBoxLayout* allLayout = new QHBoxLayout();

    searchLayout->addWidget(searchWord);
    searchLayout->addWidget(searchButton);

    buttonsLayout->addWidget(manageFilesButton);
    buttonsLayout->addWidget(tableButton);

    informationLayout->addSpacerItem(spacerTop);
    informationLayout->addLayout(searchLayout);
    informationLayout->addWidget(searchTree);
    informationLayout->addLayout(buttonsLayout);
    informationLayout->addSpacerItem(spacerBottom);

    allLayout->addSpacerItem(spacerLeft);
    allLayout->addLayout(informationLayout);
    allLayout->addSpacerItem(spacerRight);

    this->setLayout(allLayout);
}

TreeWidget::~TreeWidget()
{
    delete searchWord;
    delete searchButton;
    delete searchTree;
    delete manageFilesButton;
    delete tableButton;
}
