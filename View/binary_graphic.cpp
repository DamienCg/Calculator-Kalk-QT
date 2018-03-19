#include "binary_graphic.h"
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QGroupBox>
#include <QGridLayout>
#include <QPushButton>

void binary_graphic::calcolaoperazioniprimarie(){
    QString resulta = frontcalcolaoperazioniprimarie(op1->text(),op2->text(),operazioni->currentText());
    Result->setText(resulta);
}

void binary_graphic::calcolaconversioneBtoType(){
    QString x = frontcalcolaconversionetoType(inputB->text(),operazioniDiConversione->currentText());
    resultconvBtoDHO->setText(x);
}

void binary_graphic::calcolaconversioneDtoB(){
    QString q = binary_controller::CalcolaConversioneDtoB(inputD->text());
    resultconvDtoB->setText(q);
}

void binary_graphic::Calcolapercorsoresultop1op2(){
    inputpercorso->setText(Result->text());
    calcolapercorsoA();
}

void binary_graphic::calcolapercorsoA(){
    QString rit = binary_controller::Calcolapercorsoalbero(inputpercorso->text());
    perorsoalbero->setText(rit);
}


binary_graphic::binary_graphic(QStackedWidget * stack , QWidget *parent):Front_graphic(stack, parent),
    op1(new QLineEdit(this)),
    op2(new QLineEdit(this)),
    inputB(new QLineEdit(this)),
    inputD(new QLineEdit(this)),
    inputpercorso(new QLineEdit(this)),
    operazioni(new QComboBox(this)),
    Result(new QLineEdit(this)),
    resultconvBtoDHO(new QLineEdit(this)),
    resultconvDtoB(new QLineEdit(this)),
    perorsoalbero(new QLineEdit(this)),
    operazioniDiConversione(new QComboBox(this)){

    setWindowIndex(binary_graphic::OperationIndex);
    setController(ctrl);

 /* Build View */
 QLabel* labelresult=new QLabel(this);
 QLabel* labelcalpercorso=new QLabel(this);
 QLabel* labeloperazioni=new QLabel(this);
 QPushButton* calcola=new QPushButton(this);
 QLabel* labelconversioneBtoDHO=new QLabel(this);
 QLabel* labelconversioneDtoB=new QLabel(this);
 QPushButton*calcolapercorso=new QPushButton(this);
 QPushButton* calcolaconvDtoB=new QPushButton(this);
 QPushButton* calcolaconvBtoDHO=new QPushButton(this);
 QPushButton* calcolapercorsosultop1op2 = new QPushButton(this);

 /* Logical View TOP */
 QGroupBox* group1 = new QGroupBox(this);
 QGridLayout* grbox1 = new QGridLayout(group1);
 grbox1->addWidget(labeloperazioni,0,0,1,3);
 grbox1->addWidget(op1,1,0,1,1);
 grbox1->addWidget(operazioni,1,1,1,1);
 grbox1->addWidget(op2,1,2,1,1);
 grbox1->addWidget(calcola,2,0,1,1);
 grbox1->addWidget(labelresult,2,1,1,1);
 grbox1->addWidget(Result,2,2,1,1);
 grbox1->addWidget(calcolapercorsosultop1op2,3,2,1,1);
 addLayout(group1,0);

 /* Logical View Center */
 group1 = new QGroupBox(this);
 grbox1 = new QGridLayout(group1);
 grbox1->addWidget(labelconversioneBtoDHO,0,0,1,2);
 grbox1->addWidget(inputB,1,0,1,1);
 grbox1->addWidget(operazioniDiConversione,1,1,1,1);
 grbox1->addWidget(resultconvBtoDHO,1,2,1,1);
 grbox1->addWidget(calcolaconvBtoDHO,2,0,1,1);
 addLayout(group1,0);

 /* Logical View Botton 0 */
 group1 = new QGroupBox(this);
 grbox1 = new QGridLayout(group1);
 grbox1->addWidget(labelconversioneDtoB,0,0,1,1);
 grbox1->addWidget(inputD,1,0,1,1);
 grbox1->addWidget(resultconvDtoB,1,1,1,1);
 grbox1->addWidget(calcolaconvDtoB,2,0,1,1);
 addLayout(group1,0);


 /* Logical View Botton 1 */
 group1 = new QGroupBox(this);
 grbox1 = new QGridLayout(group1);
 grbox1->addWidget(labelcalpercorso,0,0,1,1);
 grbox1->addWidget(perorsoalbero,1,1,1,1);
 grbox1->addWidget(inputpercorso,1,0,1,1);
 grbox1->addWidget(calcolapercorso,2,0,1,1);
 addLayout(group1,1);


 /* Set View */
 perorsoalbero->setPlaceholderText("Root: ->dx->sx->dx");
 op1->setPlaceholderText("11001100");
 operazioni->addItem("+");
 operazioni->addItem("-");
 operazioni->addItem("*");
 operazioni->addItem("/");
 operazioniDiConversione->addItem("Dec");
 operazioniDiConversione->addItem("Hex");
 operazioniDiConversione->addItem("Oct");
 operazioniDiConversione->addItem("Rad");
 operazioni->setFixedSize(50,30);
 op2->setPlaceholderText("10101010");
 Result->setPlaceholderText("?");
 Result->setReadOnly(true);
 resultconvBtoDHO->setReadOnly(true);
 resultconvDtoB->setReadOnly(true);
 perorsoalbero->setReadOnly(true);
 inputB->setPlaceholderText("10101010");
 inputD->setPlaceholderText("130");
 resultconvBtoDHO->setPlaceholderText("?");
 resultconvDtoB->setPlaceholderText("10000010");
 inputpercorso->setPlaceholderText("101");
 labelresult->setText("      =   ");
 calcola->setText("Calcola");
 labelconversioneBtoDHO->setText("Convert Binary to Decimal, Hex, Octal, SQRT:");
 calcolaconvBtoDHO->setText("Converti");
 labelconversioneDtoB->setText("Convert Decimal to Binary:");
 labeloperazioni->setText("Binary Calculation Add, Subtract, Multiply, or Divide:");
 calcolaconvDtoB->setText("Converti");
 labelcalpercorso->setText("Calcola Percorso in albero:");
 calcolapercorso->setText("Calcola");
 calcolapercorsosultop1op2->setText("Calcola Percorso");

 /* Signal */
 connect(calcola, SIGNAL(clicked(bool)), this, SLOT(calcolaoperazioniprimarie()));
 connect(calcolaconvBtoDHO, SIGNAL(clicked(bool)), this, SLOT(calcolaconversioneBtoType()));
 connect(calcolaconvDtoB, SIGNAL(clicked(bool)), this, SLOT(calcolaconversioneDtoB()));
 connect(calcolapercorso, SIGNAL(clicked(bool)), this, SLOT(calcolapercorsoA()));
 connect(calcolapercorsosultop1op2, SIGNAL(clicked(bool)), this, SLOT(Calcolapercorsoresultop1op2()));
 connect(operazioniDiConversione, SIGNAL(currentIndexChanged(QString)), this, SLOT(calcolaconversioneBtoType()));
 connect(operazioni, SIGNAL(currentIndexChanged(QString)), this, SLOT(calcolaoperazioniprimarie()));
}
