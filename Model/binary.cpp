#include "binary.h"
#include <math.h>

Binary::Binary(string str){
    setNewValue(str);
}

Arithmetic_Types *Binary::ADD(Arithmetic_Types * op2){
    long double temp= conversion_in_real()+op2->conversion_in_real();
    string str = std::to_string(temp);
    setvalue((Converti_In_Tipo(str)).getvalue());
    return this;
}

Arithmetic_Types *Binary::SUB(Arithmetic_Types * op2){
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

Arithmetic_Types *Binary::MUL(Arithmetic_Types * op2){
    long double temp= conversion_in_real()*op2->conversion_in_real();
    string str = std::to_string(temp);
    setvalue((Converti_In_Tipo(str)).getvalue());
    return this;
}

Arithmetic_Types *Binary::DIV(Arithmetic_Types * op2){
    long double temp= conversion_in_real()/op2->conversion_in_real();
    string str = std::to_string(temp);
    setvalue((Converti_In_Tipo(str)).getvalue());
    return this;
}


long double Binary::conversion_in_real() const{
    list<char> op = getvalue();
    int n=op.size()-1;
    long double x=0;
    for (std::list<char>::const_iterator it=op.begin(); it != op.end(); ++it){
        if(*it == '1')
            x=x+pow(2,n);
        n--;
    }
    return x;
}

double Binary::radice() const{
    double x=this->conversion_in_real();
    double result;
    result = sqrt (x);
    return result;
}

void Binary::parser(const string &str){
    string err = "0-1 Only";
    for (string::const_iterator it=str.begin(); it!=str.end(); ++it){
        if( (*it != '0' ) && (*it != '1') )
            throw MyException(err);
    }
}


ostream &operator<<(ostream & os, const Binary & B){
    list<char> op = B.getvalue();

    for (std::list<char>::const_iterator it=op.begin(); it != op.end(); ++it){
        os<<*it;
    }
    return os;
}

string Binary::ConvertiInStringa() const{
  string rit;
  list<char> op = getvalue();

    for (std::list<char>::const_iterator it=op.begin(); it != op.end(); ++it){
        rit.push_back(*it);
    }
    return rit;
}

void Binary::setNewValue(const string &str){
    parser(str);
    list<char> op;
    for (string::const_iterator it=str.begin(); it!=str.end(); ++it)
        op.push_back(*it);

    setvalue(op);
}


Binary Binary::Converti_In_Tipo(const string &str){

    Arithmetic_Types::parser_decimal(str);

    if(str=="")
        return Binary("0");

    const char *cstr = str.c_str();
    long int x = std::strtol(cstr,nullptr,10);

    if(x == 0)
        return Binary("0");
    if(x == 1)
        return  Binary("01");

    string tstr;
    while(x != 0){
        if( (x%2) == 0)
              tstr.insert(0,"0");
            else
            tstr.insert(0,"1");

        x=x/2;
    }
    return Binary(tstr);
}

string Binary::perorsoBinaryTree(const string &str){
   parser(str);
    string rit = "Root: ";
      for (string::const_iterator it=str.begin(); it!=str.end(); ++it){
          if(*it == '1')
              rit=rit+"->dx";
                      else
                      rit=rit+"->sx";
      }
      return rit;
}
