#include "arithmetic_types.h"

void Arithmetic_Types::parser_decimal(const QString& x){
    if(!(x.indexOf(QRegExp("^[0-9]+$"), 0) != -1)){
        string err = "0-9 only";
        throw MyException(err);
    }
}
