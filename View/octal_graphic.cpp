#include "octal_graphic.h"
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>
#include <QGroupBox>

void octal_graphic::calcolaoperazioniprimarie(){
    QString resulta = frontcalcolaoperazioniprimarie(op1->text(),op2->text(),operazioni->currentText());
    Result->setText(resulta);
}

void octal_graphic::calcolaconversioneOtoType(){
    QString x = frontcalcolaconversionetoType(inputO->text(),operazioniDiConversione->currentText());
    resultconvOtoDHB->setText(x);
}

void octal_graphic::calcolaconversioneDtoO(){
        QString q = octal_controller::CalcolaConversioneDtoO(inputD->text());
        resultconvDtoO->setText(q);
}

void octal_graphic::calcola_Emanuel_Swedenborg(){
    QString q = octal_controller::CalcolaEmanuel_Swedenborg(inputES->text());
    resultES->setText(q);

}

void octal_graphic::calcolaNumESs(){
inputES->setText(resultconvOtoDHB->text());
calcola_Emanuel_Swedenborg();
}

void octal_graphic::enable_Emanuel_Swedenborg(const QString& x){
    if(x != "Dec"){
       calcolaESdiconv->setEnabled(false);
       calcolaESdiconv->setStyleSheet("text-decoration: line-through;");
    }
    else{
       calcolaESdiconv->setStyleSheet("text-decoration: none;");
       calcolaESdiconv->setEnabled(true);
    }
}

octal_graphic::octal_graphic(QStackedWidget * stack , QWidget *parent):Front_graphic(stack, parent),
  op1(new QLineEdit(this)),
  operazioni(new QComboBox(this)),
  op2(new QLineEdit(this)),
  labelresult(new QLabel(this)),
  Result(new QLineEdit(this)),
  inputO(new QLineEdit(this)),
  inputD(new QLineEdit(this)),
  resultconvOtoDHB(new QLineEdit(this)),
  resultconvDtoO(new QLineEdit(this)),
  operazioniDiConversione(new QComboBox(this)),
  resultES(new QLineEdit(this)),
  inputES(new QLineEdit(this)),
  calcolaESdiconv(new QPushButton(this)){

 setWindowIndex(octal_graphic::OperationIndex);
 setController(ctrl);

 /* Build View */
 QPushButton* calcola = new QPushButton(this);
 QLabel* labeloperazioni = new QLabel(this);
 QLabel* labelconversioneOtoDHB = new QLabel(this);
 QPushButton* calcolaconvOtoDHB = new QPushButton(this);
 QLabel* labelconversioneDtoO = new QLabel(this);
 QPushButton* calcolaconvDtoO = new QPushButton(this);
 QLabel*labelcalcolaES  = new QLabel(this);
  QPushButton* calcolaES = new QPushButton(this);

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
 addLayout(group1,0);

 /* Logical View Center */
 group1 = new QGroupBox(this);
 grbox1 = new QGridLayout(group1);
 grbox1->addWidget(labelconversioneOtoDHB,0,0,1,2);
 grbox1->addWidget(inputO,1,0,1,1);
 grbox1->addWidget(operazioniDiConversione,1,1,1,1);
 grbox1->addWidget(resultconvOtoDHB,1,2,1,1);
 grbox1->addWidget(calcolaconvOtoDHB,2,0,1,1);
 grbox1->addWidget(calcolaESdiconv,2,2,1,1);
 addLayout(group1,0);

 /* Logical View Botton 0 */
 group1 = new QGroupBox(this);
 grbox1 = new QGridLayout(group1);
 grbox1->addWidget(labelconversioneDtoO,0,0,1,1);
 grbox1->addWidget(inputD,1,0,1,1);
 grbox1->addWidget(resultconvDtoO,1,1,1,1);
 grbox1->addWidget(calcolaconvDtoO,2,0,1,1);
 addLayout(group1,0);

 /* Logical View Botton 1 */
 group1 = new QGroupBox(this);
 grbox1 = new QGridLayout(group1);
 grbox1->addWidget(labelcalcolaES,0,0,1,1);
 grbox1->addWidget(resultES,1,1,1,1);
 grbox1->addWidget(inputES,1,0,1,1);
 grbox1->addWidget(calcolaES,2,0,1,1);
 addLayout(group1,1);



 /* Set View */
 labelcalcolaES->setText("Number System Emanuel Swedenborg:");
 op1->setPlaceholderText("17382");
 operazioni->addItem("+");
 operazioni->addItem("-");
 operazioni->addItem("*");
 operazioni->addItem("/");
 operazioniDiConversione->addItem("Dec");
 operazioniDiConversione->addItem("Hex");
 operazioniDiConversione->addItem("Bin");
 operazioniDiConversione->addItem("Rad");
 operazioni->setFixedSize(50,30);
 op2->setPlaceholderText("1734");
 Result->setPlaceholderText("?");
 labelresult->setText("      =   ");
 inputO->setPlaceholderText("7163");
 inputD->setPlaceholderText("129");
 resultconvOtoDHB->setPlaceholderText("?");
 resultconvDtoO->setPlaceholderText("201");
 Result->setReadOnly(true);
 resultconvOtoDHB->setReadOnly(true);
 resultconvDtoO->setReadOnly(true);
 resultES->setReadOnly(true);
 labeloperazioni->setText("Octal Calculation Add, Subtract, Multiply, or Divide");
 calcola->setText("Calcola");
 labelconversioneOtoDHB->setText("Conversione Octal to Decimal,Hex,Binary,SQRT:");
 calcolaconvOtoDHB->setText("Calcola");
 labelconversioneDtoO->setText("Conversione Decimal to Octal");
 calcolaconvDtoO->setText("Calcola");
 calcolaES->setText("Calcola");
 inputES->setPlaceholderText("64");
 resultES->setPlaceholderText("loo");
 calcolaESdiconv->setText("Number System Emanuel.S");

 /* Signal */
 connect(calcola, SIGNAL(clicked(bool)), this, SLOT(calcolaoperazioniprimarie()));
 connect(calcolaconvOtoDHB, SIGNAL(clicked(bool)), this, SLOT(calcolaconversioneOtoType()));
 connect(calcolaconvDtoO, SIGNAL(clicked(bool)), this, SLOT(calcolaconversioneDtoO()));
 connect(calcolaES, SIGNAL(clicked(bool)), this, SLOT(calcola_Emanuel_Swedenborg()));
 connect(calcolaESdiconv, SIGNAL(clicked(bool)), this, SLOT(calcolaNumESs()));
 connect(operazioniDiConversione, SIGNAL(currentIndexChanged(QString)), this, SLOT(enable_Emanuel_Swedenborg(QString)));
 connect(operazioniDiConversione, SIGNAL(currentIndexChanged(QString)), this, SLOT(calcolaconversioneOtoType()));
 connect(operazioni, SIGNAL(currentIndexChanged(QString)), this, SLOT(calcolaoperazioniprimarie()));
}

