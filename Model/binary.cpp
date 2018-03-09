#include "binary.h"
#include <math.h>

Binary::Binary(string str){
    setNewValue(str);
}

Arithmetic_Types *Binary::ADD(Arithmetic_Types * op2){
    int temp= conversion_in_real()+op2->conversion_in_real();
    string str = std::to_string(temp);
    op.clear();
    op = (Converti_In_Tipo(str)).op;
    return this;
}

Arithmetic_Types *Binary::SUB(Arithmetic_Types * op2){
    bool negativo=false;
    int temp= conversion_in_real()-op2->conversion_in_real();
    if(temp < 0){
        negativo=true;
        temp=temp*-1;
    }
    string str = std::to_string(temp);
    op.clear();
    op = (Converti_In_Tipo(str)).op;
    if(negativo)
        op.push_front('-');
    return this;
}

Arithmetic_Types *Binary::MUL(Arithmetic_Types * op2){
    int temp= conversion_in_real()*op2->conversion_in_real();
    string str = std::to_string(temp);
    op.clear();
    op = (Converti_In_Tipo(str)).op;
    return this;
}

Arithmetic_Types *Binary::DIV(Arithmetic_Types * op2){
    int temp= conversion_in_real()/op2->conversion_in_real();
    string str = std::to_string(temp);
    op.clear();
    op = (Converti_In_Tipo(str)).op;
    return this;
}



double Binary::conversion_in_real() const{
    int n=op.size()-1;
    double x=0;
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

void Binary::parser(string str){
    string err = "0-1 Only";
    for (string::iterator it=str.begin(); it!=str.end(); ++it){
        if( (*it != '0' ) && (*it != '1') )
            throw MyException(err);
    }
}


ostream &operator<<(ostream & os, const Binary & B){

    for (std::list<char>::const_iterator it=B.op.begin(); it != B.op.end(); ++it){
        os<<*it;
    }
    return os;
}

string Binary::ConvertiInStringa() const{
  string rit;
    for (std::list<char>::const_iterator it=op.begin(); it != op.end(); ++it){
        rit.push_back(*it);
    }
    return rit;
}

void Binary::setNewValue(string str){
    parser(str);
    op.clear();
    for (string::iterator it=str.begin(); it!=str.end(); ++it)
        op.push_back(*it);
}


Binary Binary::Converti_In_Tipo(string t){
    if(t=="")
        return Binary("0");

    int x=stoi(t);

    if(x == 0)
        return Binary("0");
    if(x == 1)
        return  Binary("01");

    string str;
    while(x != 0){
        if( (x%2) == 0)
              str.insert(0,"0");
            else
            str.insert(0,"1");

        x=x/2;
    }
    return Binary(str);
}
