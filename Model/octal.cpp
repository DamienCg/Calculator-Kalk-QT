#include "octal.h"
#include <math.h>

unsigned int Octal::base=8;
const char Octal::sure_values[8]={'0','1','2','3','4','5','6','7'};
const char Octal::Emanuel_Swedenborg[8]={'O','L','S','N','M','T','F','U'};
unsigned int Octal::sure_values_lenght=8;


Octal::Octal(string str){
  setNewValue(str);
}

Arithmetic_Types *Octal::ADD(Arithmetic_Types * op2){
    long double temp= conversion_in_real()+op2->conversion_in_real();
    string str = std::to_string(temp);
    setvalue((Converti_In_Tipo(str)).getvalue());
    return this;
}

Arithmetic_Types *Octal::SUB(Arithmetic_Types * op2){
    bool negativo=false;
    long double temp= conversion_in_real()-op2->conversion_in_real();
    if(temp < 0){
        negativo=true;
        temp=temp*-1;
    }
    string str = std::to_string(temp);
    setvalue((Converti_In_Tipo(str)).getvalue());
    if(negativo)
        getvalue().push_front('-');
    return this;
}

Arithmetic_Types *Octal::MUL(Arithmetic_Types * op2){
    long double temp= conversion_in_real()*op2->conversion_in_real();
    string str = std::to_string(temp);
    setvalue((Converti_In_Tipo(str)).getvalue());
    return this;
}

Arithmetic_Types *Octal::DIV(Arithmetic_Types * op2){
    long double temp= conversion_in_real()/op2->conversion_in_real();
    string str = std::to_string(temp);
    setvalue((Converti_In_Tipo(str)).getvalue());
    return this;
}

long double Octal::conversion_in_real() const{

    list<char> op = getvalue();
    int n=op.size()-1;
    long double x=0;long double tot=0;
    for (std::list<char>::const_iterator it=op.begin(); it != op.end(); ++it){
        char a = (*it);
        x = a-48;
        tot=tot + (x*pow(base,n));
        n--;
    }
    return tot;
}

string Octal::ConvertiInStringa() const{
    string rit;
    list<char> op = getvalue();

      for (std::list<char>::const_iterator it=op.begin(); it != op.end(); ++it){
          rit.push_back(*it);
      }
      return rit;
}

void Octal::setNewValue(const string &str){
    parser(str);
    list<char> op;
    for (string::const_iterator it=str.begin(); it!=str.end(); ++it)
        op.push_back(*it);

    setvalue(op);
}

Octal Octal::Converti_In_Tipo(const string &str){

    Arithmetic_Types::parser_decimal(str);

    if(str=="")
        return Octal("0");

    const char *cstr = str.c_str();
    long int x = std::strtol(cstr,nullptr,10);

    if(x == 0)
        return Octal("0");
    if(x == 1)
        return  Octal("1");

    string tstr;
 while(x>0){
    int resto=x%base;
    char temp=sure_values[resto];
    tstr=temp+tstr;
    x=x/base;
 }
 return Octal(tstr);
}

string Octal::Charle_S_and_Emanuel_S(const string &str){

    Arithmetic_Types::parser_decimal(str);
    string rit = "";    

    Octal temp = Converti_In_Tipo(str);
    list<char> op = temp.getvalue();
    for (list<char>::const_iterator it=op.begin(); it != op.end(); ++it){
        char a = (*it);
        int n = a-48;        
        rit.push_back(Emanuel_Swedenborg[n]);
    }
    return rit;
}


double Octal::radice() const{
    double x=this->conversion_in_real();
    double result;
    result = sqrt (x);
    return result;
}

void Octal::parser(const string &str){
    string err ="0-7 only";
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
