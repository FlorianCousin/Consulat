#include "treewidget.h"

TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent)
{
    // Useful widgets initialisation
    searchWord = new QLineEdit(this);
    searchButton = new QPushButton(tr("&Search"), this);
    //searchTree = new QTreeView(this); TODO

    searchTree = new QTreeWidget();
    searchTree->setColumnCount(2);
    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < 10; ++i)
        items.append(new QTreeWidgetItem((QTreeWidget*)nullptr, QStringList(QString("item: %1").arg(i))));
    searchTree->insertTopLevelItems(0, items);
    items.first()->addChild(new QTreeWidgetItem((QTreeWidget*)nullptr, QStringList(QString("c'est moi")))); // TODO remove this after test

    manageFilesButton = new QPushButton(tr("&Manage Files"), this);
    tableButton = new QPushButton(tr("&Table"), this);

    searchLayout = new QHBoxLayout();
    buttonsLayout = new QHBoxLayout();
    informationLayout = new QVBoxLayout();
    allLayout = new QHBoxLayout();

    connect(manageFilesButton, SIGNAL(clicked()), this, SLOT(goToManageFilesWindow()));
    connect(tableButton, SIGNAL(clicked()), this, SLOT(goToTableWindow()));

    update();
}

TreeWidget::~TreeWidget()
{
    delete searchWord;
    delete searchButton;
    delete searchTree;
    delete manageFilesButton;
    delete tableButton;

    delete searchLayout;
    delete buttonsLayout;
    delete informationLayout;
    delete allLayout;
}

void TreeWidget::update()
{
    searchLayout->addWidget(searchWord);
    searchLayout->addWidget(searchButton);

    buttonsLayout->addWidget(manageFilesButton);
    buttonsLayout->addWidget(tableButton);

    informationLayout->addSpacing(5);
    informationLayout->addLayout(searchLayout);
    informationLayout->addWidget(searchTree);
    informationLayout->addLayout(buttonsLayout);
    informationLayout->addSpacing(5);

    allLayout->addSpacing(5);
    allLayout->addLayout(informationLayout);
    allLayout->addSpacing(5);

    this->setLayout(allLayout);
}

void TreeWidget::goToManageFilesWindow()
{
    emit changeWindowStateSignal(0);
}

void TreeWidget::goToTableWindow()
{
    emit changeWindowStateSignal(2);
}
