#include "front_graphic.h"

void Front_graphic::OpenTypes(int a){
    if( a != windowIndex)
        listatipi->switchToType(windowIndex);
    Stack->setCurrentIndex(a);
}

void Front_graphic::setWindowIndex(int i){
    windowIndex = i;
    listatipi->switchToType(i);
}


Front_graphic::Front_graphic(QStackedWidget* stack, QWidget *parent):
    QWidget(parent),
    listatipi(new Choose_Type(this)),
    Stack(stack),
    mex(new QMessageBox(this)),
    layout(new QVBoxLayout(this)){

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


bool Front_graphic::checkHex(const QString & x)const{
   return x.indexOf(QRegExp("^[a-fA-F0-9]+$"), 0) != -1;
}

bool Front_graphic::checkDecimal(const QString & x)const{
    return x.indexOf(QRegExp("^[0-9]+$"), 0) != -1;
}

bool Front_graphic::checkOctal(const QString & x) const{
    return x.indexOf(QRegExp("^[0-7]+$"), 0) != -1;
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

Front_graphic::~Front_graphic(){}
