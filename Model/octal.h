#ifndef OCTAL_H
#define OCTAL_H
#include "arithmetic_types.h"

class Octal: public Arithmetic_Types{
    friend ostream& operator<<(ostream&,const Octal&);
 private:
     std::list<char> oct;
     static unsigned int base;
     static const char sure_values[8];
     static const char Emanuel_Swedenborg[8];
     static unsigned int sure_values_lenght;

 public:
     Octal(std::string="");

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
     static Octal Converti_In_Tipo(string);
     static string Charle_S_and_Emanuel_S(int);
};

 ostream& operator<<(ostream&,const Octal&);

#endif // OCTAL_H
