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
    oct.clear();
    oct = (Converti_In_Tipo(str)).oct;
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
    oct.clear();
    oct = (Converti_In_Tipo(str)).oct;
    if(negativo)
        oct.push_front('-');
    return this;
}

Arithmetic_Types *Octal::MUL(Arithmetic_Types * op2){
    long double temp= conversion_in_real()*op2->conversion_in_real();
    string str = std::to_string(temp);
    oct.clear();
    oct = (Converti_In_Tipo(str)).oct;
    return this;
}

Arithmetic_Types *Octal::DIV(Arithmetic_Types * op2){
    long double temp= conversion_in_real()/op2->conversion_in_real();
    string str = std::to_string(temp);
    oct.clear();
    oct = (Converti_In_Tipo(str)).oct;
    return this;
}

long double Octal::conversion_in_real() const{

    int size=oct.size()-1;
    long double op1=0; long double tot=0;
        for (std::list<char>::const_iterator it=oct.begin(); it != oct.end(); ++it){
            char a = (*it);
            op1 = a-48;
            tot=tot + (op1*pow(base,size));
            size--;
        }
        return tot;
}

string Octal::ConvertiInStringa() const{
    string rit;
    for (std::list<char>::const_iterator it=oct.begin(); it != oct.end(); ++it){
        rit.push_back(*it);
    }
    return rit;
}

void Octal::setNewValue(const string &str){
    parser(str);
    oct.clear();
        for (string::const_iterator it = str.begin(), end = str.end(); it != end; ++it)
            oct.push_back(*it);
}

Octal Octal::Converti_In_Tipo(const string &str){

    Arithmetic_Types::parser_decimal(str);

    if(str=="")
        return Octal("0");

    const char *cstr = str.c_str();
    long int x = std::strtol(cstr,nullptr,10);

Octal aux;
if(x==0){aux.oct.push_front('0'); return aux;}

 while(x>0){
    int resto=x%base;
    char temp=sure_values[resto];
    aux.oct.push_front(temp);
    x=x/base;
 }
 return aux;
}

string Octal::Charle_S_and_Emanuel_S(const string &str){

    Arithmetic_Types::parser_decimal(str);
    string rit = "";

    Octal temp = Converti_In_Tipo(str);
    for (std::list<char>::const_iterator it=temp.oct.begin(); it != temp.oct.end(); ++it){
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


ostream &operator<<(ostream & os, const Octal & B){
    for (std::list<char>::const_iterator it=B.oct.begin(); it != B.oct.end(); ++it){
        os<<*it;
    }
    return os;
}
