#include "hex_graphic.h"
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>

void Hex_Graphic::calcolaoperazioniprimarie(){
    QString resulta = frontcalcolaoperazioniprimarie(op1->text(),op2->text(),operazioni->currentText());
    Result->setText(resulta);
}


void Hex_Graphic::calcolaconversioneHtoType(){
    QString x = frontcalcolaconversionetoType(inputH->text(),operazioniDiConversione->currentText());
    resultconvHtoDBO->setText(x);

}

void Hex_Graphic::calcolaconversioneDtoH(){
    QString q = hex_controller::CalcolaConversioneDtoH(inputD->text());
    resultconvDtoH->setText(q);

}

void Hex_Graphic::CalcolaColoreRGBresultop1op2(){
    QString par = Result->text();
    if(par.length() >0){
        if(par.at(0) == '-')
            par.remove(0,1);

    inputcolore->setText(par);
    CalcolaColoreRGB();
    }
}


void Hex_Graphic::CalcolaColoreRGB(){
resultcolore->setText("");

const QString colore = hex_controller::CalcolaColore(inputcolore->text());
    if(inputcolore->text().length() == 6)
        resultcolore->setStyleSheet(colore);
    else
        showMessagebox("Stringa non Valida, Deve essere lunga 6, senza spazi");
}


Hex_Graphic::Hex_Graphic(QStackedWidget * stack, QWidget * parent):Front_graphic(stack, parent),
  op1(new QLineEdit(this)),
  operazioni(new QComboBox(this)),
  op2(new QLineEdit(this)),
  labelresult(new QLabel(this)),
  Result(new QLineEdit(this)),
  inputH(new QLineEdit(this)),
  inputD(new QLineEdit(this)),
  resultconvHtoDBO(new QLineEdit(this)),
  resultconvDtoH(new QLineEdit(this)),
  inputcolore(new QLineEdit(this)),
  resultcolore(new QLabel(this)),
  operazioniDiConversione(new QComboBox(this)){


 setWindowIndex(Hex_Graphic::OperationIndex);
 setController(ctrl);

 /* Build View */
 QPushButton* calcola = new QPushButton(this);
 QLabel* labelconversioneHtoDBO = new QLabel(this);
 QPushButton* calcolaconvHtoDBO = new QPushButton(this);
 QLabel* labelconversioneDtoH = new QLabel(this);
 QPushButton* calcolaconvDtoH = new QPushButton(this);
 QPushButton* calcolacoloreresultop1op2 = new QPushButton(this);
 QLabel* labeloperazioni = new QLabel(this);
 QLabel* labelcolore = new QLabel(this);
 QPushButton* calcolacolore = new QPushButton(this);


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
 grbox1->addWidget(calcolacoloreresultop1op2,3,2,1,1);
 addLayout(group1,0);

 /* Logical View Center */
 group1 = new QGroupBox(this);
 grbox1 = new QGridLayout(group1);
 grbox1->addWidget(labelconversioneHtoDBO,0,0,1,2);
 grbox1->addWidget(inputH,1,0,1,1);
 grbox1->addWidget(operazioniDiConversione,1,1,1,1);
 grbox1->addWidget(resultconvHtoDBO,1,2,1,1);
 grbox1->addWidget(calcolaconvHtoDBO,2,0,1,1);
 addLayout(group1,0);

 /* Logical View Botton 0 */
 group1 = new QGroupBox(this);
 grbox1 = new QGridLayout(group1);
 grbox1->addWidget(labelconversioneDtoH,0,0,1,1);
 grbox1->addWidget(inputD,1,0,1,1);
 grbox1->addWidget(resultconvDtoH,1,1,1,1);
 grbox1->addWidget(calcolaconvDtoH,2,0,1,1);
 addLayout(group1,0);


 /* Logical View Botton 1 */
 group1 = new QGroupBox(this);
 grbox1 = new QGridLayout(group1);
 grbox1->addWidget(labelcolore,0,0,1,1);
 grbox1->addWidget(resultcolore,1,1,1,1);
 grbox1->addWidget(inputcolore,1,0,1,1);
 grbox1->addWidget(calcolacolore,2,0,1,1);
 addLayout(group1,1);

 /* Set View */
 op1->setPlaceholderText("8AB");
 operazioni->addItem("+");
 operazioni->addItem("-");
 operazioni->addItem("*");
 operazioni->addItem("/");
 operazioniDiConversione->addItem("Dec");
 operazioniDiConversione->addItem("Bin");
 operazioniDiConversione->addItem("Oct");
 operazioniDiConversione->addItem("Rad");
 operazioni->setFixedSize(50,30);
 op2->setPlaceholderText("B78");
 Result->setPlaceholderText("?");
 labelresult->setText("      =   ");
 inputcolore->setPlaceholderText("0000FF");
 resultcolore->setFixedWidth(250);
 inputH->setPlaceholderText("2A");
 inputD->setPlaceholderText("170");
 resultconvDtoH->setPlaceholderText("AA");
 Result->setReadOnly(true);
 resultconvHtoDBO->setReadOnly(true);
 resultconvDtoH->setReadOnly(true);
 calcola->setText("Calcola");
 labelconversioneHtoDBO->setText("Conversione Hex to Decimal,Binary,Octal,SQRT:");
 calcolaconvHtoDBO->setText("Calcola");
 labelconversioneDtoH->setText("Conversione Decimal to Hex:");
 calcolaconvDtoH->setText("Calcola");
 labeloperazioni->setText("Hexadecimal Calculation Add, Subtract, Multiply, or Divide:");
 calcolacoloreresultop1op2->setText("Calcola RGB");
 labelcolore->setText("Calcola Colore RGB:");
 calcolacolore->setText("Calcola RGB");
 resultcolore->setStyleSheet("background: #0000FF; border-radius: 6px;");

 /* Signal */
 connect(calcola, SIGNAL(clicked(bool)), this, SLOT(calcolaoperazioniprimarie()));
 connect(calcolaconvHtoDBO, SIGNAL(clicked(bool)), this, SLOT(calcolaconversioneHtoType()));
 connect(calcolaconvDtoH, SIGNAL(clicked(bool)), this, SLOT(calcolaconversioneDtoH()));
 connect(calcolacolore, SIGNAL(clicked(bool)), this, SLOT(CalcolaColoreRGB()));
 connect(calcolacoloreresultop1op2, SIGNAL(clicked(bool)), this, SLOT(CalcolaColoreRGBresultop1op2()));
 connect(operazioniDiConversione, SIGNAL(currentIndexChanged(QString)), this, SLOT(calcolaconversioneHtoType()));
 connect(operazioni, SIGNAL(currentIndexChanged(QString)), this, SLOT(calcolaoperazioniprimarie()));
}
