#ifndef ARITHMETIC_TYPES_H
#define ARITHMETIC_TYPES_H
#include "./Controller/eccezioni.h"
#include <string>
#include <ostream>
#include <list>
using std::string;
using std::ostream;

class Arithmetic_Types{

public:
    virtual Arithmetic_Types* ADD(Arithmetic_Types*)=0;
    virtual Arithmetic_Types* SUB(Arithmetic_Types*)=0;
    virtual Arithmetic_Types* MUL(Arithmetic_Types*)=0;
    virtual Arithmetic_Types* DIV(Arithmetic_Types*)=0;
    virtual double conversion_in_real() const = 0;
    virtual void setNewValue(string)=0;
    virtual string ConvertiInStringa() const=0;
    virtual double radice() const=0;
    virtual ~Arithmetic_Types()=default;
};

#endif // ARITHMETIC_TYPES_H
