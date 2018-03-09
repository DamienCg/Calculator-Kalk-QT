#include "eccezioni.h"

MyException::MyException(string d):mex(new QMessageBox()){
    mex->setText(QString::fromStdString(d));
    mex->button(QMessageBox::Ok);
    mex->show();
}

