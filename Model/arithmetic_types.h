#ifndef ARITHMETIC_TYPES_H
#define ARITHMETIC_TYPES_H
#include "./Controller/eccezioni.h"
#include <string>
#include <ostream>
#include <list>
using std::string;
using std::ostream;
using std::list;
class QString;

class Arithmetic_Types{
private:
    list<char> value;
protected:
    void setvalue(const list<char>&);
    list<char> getvalue() const;
public:
    virtual Arithmetic_Types* ADD(Arithmetic_Types*)=0;
    virtual Arithmetic_Types* SUB(Arithmetic_Types*)=0;
    virtual Arithmetic_Types* MUL(Arithmetic_Types*)=0;
    virtual Arithmetic_Types* DIV(Arithmetic_Types*)=0;
    virtual long double conversion_in_real() const = 0;
    virtual void setNewValue(const string&)=0;
    virtual string ConvertiInStringa() const=0;
    virtual double radice() const=0;
    virtual ~Arithmetic_Types()=default;

    static void parser_decimal(const string &str);

};

#endif // ARITHMETIC_TYPES_H
