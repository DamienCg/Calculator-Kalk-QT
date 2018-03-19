#include "octal_controller.h"
#include <QString>

octal_controller::octal_controller(): Controller(new Octal(),new Octal()){}

QString octal_controller::CalcolaConversioneDtoO(const QString & t)try{
    string dec = t.toStdString();
    Octal temp = Octal();
    temp = temp.Converti_In_Tipo(dec);
    return QString::fromStdString(temp.ConvertiInStringa());
}
catch(MyException){return QString();}


QString octal_controller::CalcolaEmanuel_Swedenborg(const QString & t)try{
    string str = t.toStdString();
    string s = Octal::Charle_S_and_Emanuel_S(str);
    return QString::fromStdString(s);
}
catch(MyException){return QString();}
