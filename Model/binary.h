#ifndef BINARY_H
#define BINARY_H
#include "arithmetic_types.h"

class Binary: public Arithmetic_Types{
private:
    static unsigned int base;
public:
    Binary(string="0");

    /*Metodi Virtuali*/
     Arithmetic_Types* ADD(Arithmetic_Types*);
     Arithmetic_Types* SUB(Arithmetic_Types*);
     Arithmetic_Types* MUL(Arithmetic_Types*);
     Arithmetic_Types* DIV(Arithmetic_Types*);
     long double conversion_in_real() const;
     string ConvertiInStringa() const;
     void setNewValue(const string&);
     double radice() const;

    /*Metodi Di classe*/
    static void parser(const string&);
    static Binary Converti_In_Tipo(const string&);
    static string perorsoBinaryTree(const string&);
};

#endif // BINARY_H
