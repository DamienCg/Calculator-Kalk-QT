#include "hex.h"
#include <math.h>
unsigned int Hex::base=16;
const char Hex::sure_values[22]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','a','b','c','d','e','f'};
unsigned int Hex::sure_values_lenght=22;

Hex::Hex(string str){
    setNewValue(str);
}


Arithmetic_Types *Hex::ADD(Arithmetic_Types * op2){
    long double temp= conversion_in_real()+op2->conversion_in_real();
    string str = std::to_string(temp);
    Hex aux =Converti_In_Tipo(str);
    setvalue(aux.getvalue());
    return this;
}

Arithmetic_Types *Hex::SUB(Arithmetic_Types * op2){
    bool negativo=false;
    long double temp= conversion_in_real()-op2->conversion_in_real();
    if(temp < 0){
        negativo=true;
        temp=temp*-1;
    }
    string str = std::to_string(temp);
    setvalue((Converti_In_Tipo(str)).getvalue());
    if(negativo){
        list<char> s = getvalue();
        s.push_front('-');
        setvalue(s);
    }
    return this;
}

Arithmetic_Types *Hex::MUL(Arithmetic_Types * op2){
    long double temp= conversion_in_real()*op2->conversion_in_real();
    string str = std::to_string(temp);
    setvalue((Converti_In_Tipo(str)).getvalue());
    return this;
}

Arithmetic_Types *Hex::DIV(Arithmetic_Types * op2){
    long double temp= conversion_in_real()/op2->conversion_in_real();
    string str = std::to_string(temp);
    setvalue((Converti_In_Tipo(str)).getvalue());
    return this;
}


int Hex::coverti_char_in_int(char p){
    int rit=0;

    QChar x(p);
    x = x.toUpper();
    char check = x.toLatin1();

    switch (check){
    case 'A':
        rit= 10;
    break;
    case 'B':
        rit= 11;
    break;
    case 'C':
        rit= 12;
    break;
    case 'D':
        rit= 13;
    break;
    case 'E':
        rit= 14;
    break;
    case 'F':
        rit= 15;
    break;
    default:
         rit = check-48;
     break;
    }
return rit;
}

long double Hex::conversion_in_real() const{

    list<char> op = getvalue();
    int n=op.size()-1;
    long double x=0;long double tot=0;
    for (std::list<char>::const_iterator it=op.begin(); it != op.end(); ++it){
        x = coverti_char_in_int(*it);
        tot=tot + (x*pow(base,n));
        n--;
    }
    return tot;
}

string Hex::ConvertiInStringa() const{
    string rit;
    list<char> op = getvalue();

      for (std::list<char>::const_iterator it=op.begin(); it != op.end(); ++it){
          rit.push_back(*it);
      }
      return rit;
}

void Hex::setNewValue(const string &str){
    parser(str);
    list<char> op;
    for (string::const_iterator it=str.begin(); it!=str.end(); ++it)
        op.push_back(*it);

    setvalue(op);
}

Hex Hex::Converti_In_Tipo(const string &str){

    Arithmetic_Types::parser_decimal(str);

    if(str=="")
        return Hex("0");

    const char *cstr = str.c_str();
    long int x = std::strtol(cstr,nullptr,10);

    if(x == 0)
        return Hex("0");
    if(x == 1)
        return  Hex("1");

    string tstr;
     while(x>0){
        int resto=x%base;
        char temp=sure_values[resto];
        tstr=temp+tstr;
        x=x/base;
     }
    return Hex(tstr);
}

double Hex::radice() const{
    double x=this->conversion_in_real();
    double result;
    result = sqrt (x);
    return result;
}

void Hex::parser(const string &str){
    string err = "0-9 and A-F only";
    bool lanciaecc=true;
        for (string::const_iterator it = str.begin(), end = str.end(); it != end; ++it){
            for(unsigned int i=0; i<sure_values_lenght && lanciaecc; i++){
                if(*it == sure_values[i])
                    lanciaecc=false;
            }
              if(lanciaecc)
                  throw MyException(err);
            lanciaecc=true;
        }
}
