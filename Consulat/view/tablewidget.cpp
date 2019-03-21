#include "tablewidget.h"

TableWidget::TableWidget(QWidget *parent) : QWidget(parent)
{
    // Useful widgets initialisation
    table = new QTableView(this);
    manageFilesButton = new QPushButton(tr("&Manage Files"), this);
    treeButton = new QPushButton(tr("&Tree"), this);

    buttonsLayout = new QHBoxLayout();
    informationLayout = new QVBoxLayout();
    allLayout = new QHBoxLayout();

    connect(manageFilesButton, SIGNAL(clicked()), this, SLOT(goToManageFilesWindow()));
    connect(treeButton, SIGNAL(clicked()), this, SLOT(goToTreeWindow()));

    update();
}

TableWidget::~TableWidget()
{
    delete table;
    delete manageFilesButton;
    delete treeButton;

    delete buttonsLayout;
    delete informationLayout;
    delete allLayout;
}

void TableWidget::update()
{
    buttonsLayout->addWidget(manageFilesButton);
    buttonsLayout->addWidget(treeButton);

    informationLayout->addSpacing(5);
    informationLayout->addWidget(table);
    informationLayout->addLayout(buttonsLayout);
    informationLayout->addSpacing(5);

    allLayout->addSpacing(5);
    allLayout->addLayout(informationLayout);
    allLayout->addSpacing(5);

    this->setLayout(allLayout);

}

void TableWidget::goToManageFilesWindow()
{
    emit changeWindowStateSignal(0);
}

void TableWidget::goToTreeWindow()
{
    emit changeWindowStateSignal(1);
}
