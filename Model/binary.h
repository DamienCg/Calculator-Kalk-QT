#ifndef BINARY_H
#define BINARY_H
#include "arithmetic_types.h"

class Binary: public Arithmetic_Types{
    friend ostream& operator<<(ostream&,const Binary&);
private:
    std::list<char> op;
public:
    Binary(string="0");

    /*Metodi Virtuali*/
     Arithmetic_Types* ADD(Arithmetic_Types*);
     Arithmetic_Types* SUB(Arithmetic_Types*);
     Arithmetic_Types* MUL(Arithmetic_Types*);
     Arithmetic_Types* DIV(Arithmetic_Types*);
     double conversion_in_real() const;
     string ConvertiInStringa() const;
     void setNewValue(string);
     double radice() const;

    /*Metodi Di classe*/
    static void parser(string);
    static Binary Converti_In_Tipo(string);
};

ostream& operator<<(ostream&,const Binary&);

#endif // BINARY_H