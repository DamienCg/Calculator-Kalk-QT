#include "binary_controller.h"

binary_controller::binary_controller(): Controller(new Binary(), new Binary()){}

QString binary_controller::CalcolaBtoOtherTypes(const QString & b, const char type) try{
    string bin=b.toStdString();
    string r = "";
    Binary temp = Binary(bin);
    int x = temp.conversion_in_real();

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
    QString rit = "Root: ";
    string str = r.toStdString();
      for (string::iterator it=str.begin(); it!=str.end(); ++it){
          if(*it == '1')
              rit=rit+"->dx";
                      else
                      rit=rit+"->sx";
      }
      return rit;
}
catch(MyException){return QString();}

QString binary_controller::CalcolaConversioneDtoB(const QString & t){
    string dec = t.toStdString();
    Binary temp = Binary();
    temp = temp.Converti_In_Tipo(dec);
    return QString::fromStdString(temp.ConvertiInStringa());
}
