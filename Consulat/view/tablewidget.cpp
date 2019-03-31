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

/**
 * @brief TableWidget::update updates the window
 */
void TableWidget::update() // TODO put a input to the function and update the function comment accordingly
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

/**
 * @brief TableWidget::goToManageFilesWindow is called when the button to go to
 * the manage files window is clicked. It emits a signal the MainWindow instance is
 * waiting for.
 */
void TableWidget::goToManageFilesWindow() const
{
    emit changeWindowStateSignal(0);
}

/**
 * @brief TableWidget::goToTreeWindow is called when the button to go to
 * the tree window is clicked. It emits a signal the MainWindow instance is
 * waiting for.
 */
void TableWidget::goToTreeWindow() const
{
    emit changeWindowStateSignal(1);
}
