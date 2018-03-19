#include "arithmetic_types.h"

void Arithmetic_Types::setvalue(const list<char> & b) {
    value.clear();
    value=b;
}

list<char> Arithmetic_Types::getvalue() const{
    return value;
}

void Arithmetic_Types::parser_decimal(const string& str){
    QString x = QString::fromStdString(str);
    if(!(x.indexOf(QRegExp("^[0-9]+,?[0-9]*$"), 0) != -1)){
        string err = "0-9 only";
        throw MyException(err);
    }
}
