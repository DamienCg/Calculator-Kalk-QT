#include "controller.h"
#include <QString>

Controller::Controller(Arithmetic_Types *a, Arithmetic_Types *b): calcolatrice(a,b){}


QString Controller::CostruisciEcalcolaEConvertiop1op2(const QString &op1, const QString &op2, const QString &op)try{
    string x=op1.toStdString();
    string y=op2.toStdString();
    string operazione=op.toStdString();
    return QString::fromStdString(calcolatrice.calcolaop1op2(x,y,operazione));
}
catch(MyException){return QString();}


QString Controller::CostruisciEcalcolaConversioneTtoD(const QString &t)try{
    string x=t.toStdString();
    return QString::number(calcolatrice.calcolaConversioneTtoD(x));
}
catch(MyException){return QString();}


QString Controller::CotruisciECalcolaRadice(const QString & b)try{
        string bin=b.toStdString();
        return QString::number(calcolatrice.calcolaRadice(bin));
}

catch(MyException){return QString();}


QString Controller::CalcolatoOtherTypes(const QString & b, const char & type) try{
    return QString::fromStdString(calcolatrice.CalcolaTypestoOtherTypes(b.toStdString(),type));
}
catch(MyException){return QString();}



