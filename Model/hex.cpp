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
    hexadecimal.clear();
    hexadecimal = (Converti_In_Tipo(str)).hexadecimal;
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
    hexadecimal.clear();
    hexadecimal = (Converti_In_Tipo(str)).hexadecimal;
    if(negativo)
        hexadecimal.push_front('-');
    return this;
}

Arithmetic_Types *Hex::MUL(Arithmetic_Types * op2){
    long double temp= conversion_in_real()*op2->conversion_in_real();
    string str = std::to_string(temp);
    hexadecimal.clear();
    hexadecimal = (Converti_In_Tipo(str)).hexadecimal;
    return this;
}

Arithmetic_Types *Hex::DIV(Arithmetic_Types * op2){
    long double temp= conversion_in_real()/op2->conversion_in_real();
    string str = std::to_string(temp);
    hexadecimal.clear();
    hexadecimal = (Converti_In_Tipo(str)).hexadecimal;
    return this;
}


int Hex::coverti_char_in_int(char x){
    int rit=0;

    switch (x){
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
    case 'a':
        rit= 10;
    break;
    case 'b':
        rit= 11;
    break;
    case 'c':
        rit= 12;
    break;
    case 'd':
        rit= 13;
    break;
    case 'e':
        rit= 14;
    break;
    case 'f':
        rit= 15;
    break;
    default:
         rit = x-48;
     break;
    }
return rit;
}


ostream &operator<<(ostream & os, const Hex & B){

    for (std::list<char>::const_iterator it=B.hexadecimal.begin(); it != B.hexadecimal.end(); ++it){
        os<<*it;
    }
    return os;
}


long double Hex::conversion_in_real() const{

    int n=hexadecimal.size()-1;
    long double op1=0; long double tot=0;
        for (std::list<char>::const_iterator it=hexadecimal.begin(); it != hexadecimal.end(); ++it){
            op1 = coverti_char_in_int(*it);
            tot=tot + (op1*pow(base,n));
            n--;
        }
        return tot;
}

string Hex::ConvertiInStringa() const{
    string rit;
    for (std::list<char>::const_iterator it=hexadecimal.begin(); it != hexadecimal.end(); ++it){
            rit.push_back(*it);
     }
    return rit;
}

void Hex::setNewValue(const string &str){
    parser(str);
    hexadecimal.clear();
        for (string::const_iterator it = str.begin(), end = str.end(); it != end; ++it)
            hexadecimal.push_back(*it);
}

Hex Hex::Converti_In_Tipo(const string &str){
    if(str=="")
        return Hex("0");

    const char *cstr = str.c_str();
    long int x = std::strtol(cstr,nullptr,10);

 Hex aux;
  if(x==0){aux.hexadecimal.push_front('0'); return aux;}

     while(x>0){
        int resto=x%base;
        char temp=sure_values[resto];
        aux.hexadecimal.push_front(temp);
        x=x/base;
     }
    return aux;
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
