#include "hex_controller.h"
#include <QString>
#include <string>

hex_controller::hex_controller(): Controller(new Hex(), new Hex()){}

QString hex_controller::CalcolaHtoOtherTypes(const QString & b, const char &type) try{
    string hex=b.toStdString();
    string r = "";
    Hex temp = Hex(hex);
    double x = temp.conversion_in_real();

    switch (type) {
    case 'B':
        r = Binary::Converti_In_Tipo(QString::number(x).toStdString()).ConvertiInStringa();
        break;
    case 'O':
        r = Octal::Converti_In_Tipo(QString::number(x).toStdString()).ConvertiInStringa();
        break;
    default:
        return QString::fromStdString(r);
        break;
    }

    return QString::fromStdString(r);
}
catch(MyException){return QString();}



QString hex_controller::CalcolaColore(const QString &t)try{
    Hex::parser(t.toStdString());
    return "background-color: #"+t+"; border-radius: 6px;";
}
catch(MyException){return QString();}

QString hex_controller::CalcolaConversioneDtoH(const QString & t)try{
    Arithmetic_Types::parser_decimal(t);
    string dec = t.toStdString();
    Hex temp = Hex();
    temp = temp.Converti_In_Tipo(dec);
    return QString::fromStdString(temp.ConvertiInStringa());
}
catch(MyException){return QString();}

