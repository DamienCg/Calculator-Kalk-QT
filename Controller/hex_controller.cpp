#include "hex_controller.h"
#include <QString>
#include <string>

hex_controller::hex_controller(): Controller(new Hex(), new Hex()){}


QString hex_controller::CalcolaColore(const QString &t)try{
    Hex::parser(t.toStdString());
    return "background-color: #"+t+"; border-radius: 6px;";
}
catch(MyException){return QString();}

QString hex_controller::CalcolaConversioneDtoH(const QString & t)try{
    string dec = t.toStdString();
    Hex temp = Hex();
    temp = temp.Converti_In_Tipo(dec);
    return QString::fromStdString(temp.ConvertiInStringa());
}
catch(MyException){return QString();}

