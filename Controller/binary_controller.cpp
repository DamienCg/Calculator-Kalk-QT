#include "binary_controller.h"

binary_controller::binary_controller(): Controller(new Binary(), new Binary()){}

QString binary_controller::CalcolaBtoOtherTypes(const QString & b, const char &type) try{
    string bin=b.toStdString();
    string r = "";
    Binary temp = Binary(bin);
    double x = temp.conversion_in_real();

    switch (type) {
    case 'H':
        r = Hex::Converti_In_Tipo(QString::number(x).toStdString()).ConvertiInStringa();
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


QString binary_controller::Calcolapercorsoalbero(const QString & r)try{
    Binary::parser(r.toStdString());
    string temp= Binary::perorsoBinaryTree(r.toStdString());
    return QString::fromStdString(temp);
}
catch(MyException){return QString();}


QString binary_controller::CalcolaConversioneDtoB(const QString & t)try{
    Binary temp = Binary();
    Arithmetic_Types::parser_decimal(t);
    string dec = t.toStdString();
    temp = temp.Converti_In_Tipo(dec);
    return QString::fromStdString(temp.ConvertiInStringa());
}
catch(MyException){return QString();}
