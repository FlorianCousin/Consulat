#include "tablewidget.h"

TableWidget::TableWidget(QWidget *parent) : QWidget(parent)
{
    // Useful widgets initialisation
    table = new QTableView(this);
    manageFilesButton = new QPushButton(tr("&Manage Files"), this);
    treeButton = new QPushButton(tr("&Tree"), this);

    // Spacers initialisation
    QSpacerItem* spacerTop = new QSpacerItem(5, 5);
    QSpacerItem* spacerBottom = new QSpacerItem(5, 5);
    QSpacerItem* spacerLeft = new QSpacerItem(5, 5);
    QSpacerItem* spacerRight = new QSpacerItem(5, 5);

    // Layouts initialisation
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    QVBoxLayout* informationLayout = new QVBoxLayout();
    QHBoxLayout* allLayout = new QHBoxLayout();

    buttonsLayout->addWidget(manageFilesButton);
    buttonsLayout->addWidget(treeButton);

    informationLayout->addSpacerItem(spacerTop);
    informationLayout->addWidget(table);
    informationLayout->addLayout(buttonsLayout);
    informationLayout->addSpacerItem(spacerBottom);

    allLayout->addSpacerItem(spacerLeft);
    allLayout->addLayout(informationLayout);
    allLayout->addSpacerItem(spacerRight);

    this->setLayout(allLayout);
}
