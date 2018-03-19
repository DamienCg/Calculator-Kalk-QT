#include "calcola.h"

Calcola::Calcola(Arithmetic_Types * a, Arithmetic_Types * b): op1(a),op2(b){}

std::string Calcola::calcolaop1op2(const string &ope1, const string &ope2, const string &op){
    op1->setNewValue(ope1);
    op2->setNewValue(ope2);
    string rit;

    if(op == "+")
        rit = (op1->ADD(op2))->ConvertiInStringa();
    else if(op == "-")
        rit = (op1->SUB(op2))->ConvertiInStringa();
        else if(op == "*")
        rit = (op1->MUL(op2))->ConvertiInStringa();
        else
        rit = (op1->DIV(op2))->ConvertiInStringa();

    return rit;
}

double Calcola::calcolaRadice(const string &x){
op1->setNewValue(x);
return op1->radice();
}

double Calcola::calcolaConversioneTtoD(const string &t){
    op1->setNewValue(t);
    return op1->conversion_in_real();
}

string Calcola::CalcolaTypestoOtherTypes(const string &b, const char &type){
    op1->setNewValue(b);
    string r = "";
    double x = op1->conversion_in_real();

    switch (type) {
    case 'H':
        r = Hex::Converti_In_Tipo(QString::number(x).toStdString()).ConvertiInStringa();
        break;
    case 'O':
        r = Octal::Converti_In_Tipo(QString::number(x).toStdString()).ConvertiInStringa();
        break;
    case 'B':
        r = Binary::Converti_In_Tipo(QString::number(x).toStdString()).ConvertiInStringa();
        break;
    }

    return r;
}


Calcola::~Calcola(){
    delete op2;
    delete op1;
}
