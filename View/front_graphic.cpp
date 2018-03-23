#include "front_graphic.h"
#include <QStackedWidget>
#include <QMessageBox>
#include <QVBoxLayout>

void Front_graphic::OpenTypes(int a){
    if( a != windowIndex)
        listatipi->switchToType(windowIndex);
    Stack->setCurrentIndex(a);
}

void Front_graphic::setWindowIndex(int i){
    windowIndex = i;
    listatipi->switchToType(i);
}

void Front_graphic::setController(const Controller & c){
    ctrl = c;
}


Front_graphic::Front_graphic(QStackedWidget* stack, QWidget *parent, Controller c):
    QWidget(parent),
    listatipi(new Choose_Type(this)),
    Stack(stack),
    mex(new QMessageBox(this)),
    layout(new QVBoxLayout(this)),
    ctrl(c){

    layout->addWidget(listatipi,0,Qt::AlignTop);
    setWindowTitle("Kalk");
    setLayout(layout);
    setStyleSheet(" QPushButton{background-color: #10AE5F; border-radius: 6px; height: 25px; color: black; border: 1px solid;}"
                  " QLabel{color: white;}"
                  " QLineEdit{background-color: #e6f3ff ; border-radius: 6px; height: 25px; color: black; border: 2px solid;}"
                 );
    connect(listatipi, SIGNAL(emetti(int)), this, SLOT(OpenTypes(int)));
}

bool Front_graphic::checkBeforeContinue(const QString & op1, const QString & op2, const QString & op)const{
    if(op1 == "" && op2 ==""){
        showMessagebox("No campi vuoti!");
        return false;
    }
    else if(((op2.indexOf(QRegExp("^0+$"), 0) != -1) || op2=="" ) && op == "/"){
        showMessagebox("Division By Zero!");
        return false;
    }
    return true;
}


void Front_graphic::showMessagebox(const QString & x) const{
    mex->setStyleSheet("color: black;");
    mex->setText(x);
    mex->button(QMessageBox::Ok);
    mex->show();
}

void Front_graphic::addLayout(QWidget* p, int stretch){
    layout->addWidget(p,stretch,Qt::AlignTop);
}

QString Front_graphic::frontcalcolaoperazioniprimarie(const QString & op1, const QString & op2, const QString & op){
    if(checkBeforeContinue(op1,op2,op))
            return ctrl.CostruisciEcalcolaEConvertiop1op2(op1,op2,op);

    return QString();
}

QString Front_graphic::frontcalcolaconversionetoType(const QString& input, const QString & op){
    QString x = "";

    if(op == "Bin")
            x = ctrl.CalcolatoOtherTypes(input,'B');
        else if(op == "Hex")
            x = ctrl.CalcolatoOtherTypes(input,'H');
        else if(op == "Oct")
            x = ctrl.CalcolatoOtherTypes(input,'O');
        else if(op == "Dec")
            x = ctrl.CostruisciEcalcolaConversioneTtoD(input);
        else
            x = ctrl.CotruisciECalcolaRadice(input);

    return x;
}
