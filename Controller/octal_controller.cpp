#include "octal_controller.h"
#include <QString>

octal_controller::octal_controller(): Controller(new Octal(),new Octal()){}

QString octal_controller::CalcolaOtoOtherTypes(const QString & b, const char &type) try{
    string oct=b.toStdString();
    string r = "";
    Octal temp = Octal(oct);
    double x = temp.conversion_in_real();

    switch (type) {
    case 'H':
        r = Hex::Converti_In_Tipo(QString::number(x).toStdString()).ConvertiInStringa();
        break;
    case 'B':
        r = Binary::Converti_In_Tipo(QString::number(x).toStdString()).ConvertiInStringa();
        break;
    default:
        return QString::fromStdString(r);
        break;
    }

    return QString::fromStdString(r);
}
catch(MyException){return QString();}

QString octal_controller::CalcolaConversioneDtoO(const QString & t)try{
    Arithmetic_Types::parser_decimal(t);
    string dec = t.toStdString();
    Octal temp = Octal();
    temp = temp.Converti_In_Tipo(dec);
    return QString::fromStdString(temp.ConvertiInStringa());
}
catch(MyException){return QString();}


QString octal_controller::CalcolaEmanuel_Swedenborg(const QString & t)try{
    Arithmetic_Types::parser_decimal(t);
    string str = t.toStdString();
    const char *cstr = str.c_str();
    long int x = std::strtol(cstr,nullptr,10);
    string s = Octal::Charle_S_and_Emanuel_S(x);
    return QString::fromStdString(s);
}
catch(MyException){return QString();}
