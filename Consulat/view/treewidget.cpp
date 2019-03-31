#include "treewidget.h"

TreeWidget::TreeWidget(QAbstractItemModel *treeModel, QWidget *parent) : QWidget(parent)
{
    // Useful widgets initialisation
    searchWord = new QLineEdit(this);
    searchButton = new QPushButton(tr("&Search"), this);
    searchTree = new QTreeView(this);

    manageFilesButton = new QPushButton(tr("&Manage Files"), this);
    tableButton = new QPushButton(tr("&Table"), this);

    searchLayout = new QHBoxLayout();
    buttonsLayout = new QHBoxLayout();
    informationLayout = new QVBoxLayout();
    allLayout = new QHBoxLayout();

    connect(manageFilesButton, SIGNAL(clicked()), this, SLOT(goToManageFilesWindow()));
    connect(tableButton, SIGNAL(clicked()), this, SLOT(goToTableWindow()));
    connect(searchButton, SIGNAL(clicked()), this, SLOT(searchButtonClicked()));

    update(treeModel);
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

/**
 * @brief TreeWidget::update updates the window according to a TreeModel
 * @param treeModel
 */
void TreeWidget::update(QAbstractItemModel *treeModel)
{
    searchTree->setModel(treeModel);

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

/**
 * @brief TreeWidget::goToManageFilesWindow is called when the button to go to
 * the manage files window is clicked. It emits a signal the MainWindow instance is
 * waiting for.
 */
void TreeWidget::goToManageFilesWindow() const
{
    emit changeWindowStateSignal(0);
}

/**
 * @brief TreeWidget::goToTableWindow is called when the button to go to
 * the table window is clicked. It emits a signal the MainWindow instance is
 * waiting for.
 */
void TreeWidget::goToTableWindow() const
{
    emit changeWindowStateSignal(2);
}

/**
 * @brief TreeWidget::searchButtonClicked is called when the button to search
 * a word in the texts is clicked. It emits a signal the MainWindow instance is
 * waiting for.
 */
void TreeWidget::searchButtonClicked() const
{
    if (!searchWord->text().isEmpty())
        emit searchWordSignal(searchWord->text());
}
