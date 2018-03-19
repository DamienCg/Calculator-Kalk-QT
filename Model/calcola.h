#ifndef CALCOLA_H
#define CALCOLA_H
#include "./Model/binary.h"
#include "./Model/hex.h"
#include "./Model/octal.h"

class Calcola{
private:
    Arithmetic_Types* op1;
    Arithmetic_Types* op2;
public:
     Calcola(Arithmetic_Types* a, Arithmetic_Types* b);
     string calcolaop1op2(const string&, const string&, const string&);
     double calcolaRadice(const string&);
     double calcolaConversioneTtoD(const string&);
     string CalcolaTypestoOtherTypes(const string &,const char&);
     ~Calcola();
};

#endif // CALCOLA_H
