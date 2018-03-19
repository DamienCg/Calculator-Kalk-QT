#include "binary_controller.h"

binary_controller::binary_controller(): Controller(new Binary(), new Binary()){}

QString binary_controller::Calcolapercorsoalbero(const QString & r)try{
    string temp= Binary::perorsoBinaryTree(r.toStdString());
    return QString::fromStdString(temp);
}
catch(MyException){return QString();}


QString binary_controller::CalcolaConversioneDtoB(const QString & t)try{
    Binary temp = Binary();
    string dec = t.toStdString();
    temp = temp.Converti_In_Tipo(dec);
    return QString::fromStdString(temp.ConvertiInStringa());
}
catch(MyException){return QString();}
