#include "treewidget.h"

TreeWidget::TreeWidget(QAbstractItemModel *treeModel, QWidget *parent) : QWidget(parent)
{
    // Useful widgets initialisation
    searchWord = new QLineEdit(this);
    generateButton = new QPushButton(tr("&Generate"), this);
    searchButton = new QPushButton(tr("&Search"), this);
    searchTree = new QTreeView(this);

    buttonsLayout = new QHBoxLayout();
    informationLayout = new QVBoxLayout();
    allLayout = new QHBoxLayout();

    connect(generateButton, SIGNAL(clicked()), this, SLOT(generateButtonClicked()));
    connect(searchButton, SIGNAL(clicked()), this, SLOT(searchButtonClicked()));

    update(treeModel);
}

TreeWidget::~TreeWidget()
{
    delete searchWord;
    delete generateButton;
    delete searchButton;
    delete searchTree;

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

    buttonsLayout->addWidget(generateButton);
    buttonsLayout->addWidget(searchButton);

    informationLayout->addSpacing(5);
    informationLayout->addWidget(searchWord);
    informationLayout->addLayout(buttonsLayout);
    informationLayout->addWidget(searchTree);
    informationLayout->addSpacing(5);

    allLayout->addSpacing(5);
    allLayout->addLayout(informationLayout);
    allLayout->addSpacing(5);

    this->setLayout(allLayout);
}

void TreeWidget::generateButtonClicked() const
{
    if (!searchWord->text().isEmpty())
        emit generateWordSignal(searchWord->text());
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
