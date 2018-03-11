#include "choose_type.h"
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>

void Choose_Type::riceviEdEmetti(int v){
    emit emetti(v);
}

void Choose_Type::switchToType(int i) const{
    listatipi->setCurrentIndex(i);
}

Choose_Type::Choose_Type(QWidget *parent):
    QWidget(parent), listatipi(new QComboBox(this)),
    labelscegli(new QLabel(this)),
    VB(new QVBoxLayout(this)){

    labelscegli->setText("Scegli Tipo:");
    listatipi->addItem("Binary", 0);
    listatipi->addItem("Hex", 1);
    listatipi->addItem("Octal", 2);
    VB->addWidget(labelscegli,0,Qt::AlignTop);
    VB->addWidget(listatipi,0,Qt::AlignTop);
    setLayout(VB);
    connect(listatipi, SIGNAL(currentIndexChanged(int)), this, SLOT(riceviEdEmetti(int)));
}
