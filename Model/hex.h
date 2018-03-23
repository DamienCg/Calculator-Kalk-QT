#ifndef HEX_H
#define HEX_H
#include "arithmetic_types.h"

class Hex: public Arithmetic_Types{
private:
    static unsigned int base;
    static const char sure_values[22];
    static unsigned int sure_values_lenght;
public:
    Hex(string="");

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
    static Hex Converti_In_Tipo(const string&);
    static int coverti_char_in_int(char);
};
#endif // HEX_H
