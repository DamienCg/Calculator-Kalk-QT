
package kalk;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

public class Fraction extends arithmetic_types {
    private  int num;
    private  int den;

    public Fraction(int nu, int de){
     num=nu; den=de;
    }
    
     @Override
    public arithmetic_types ADD(arithmetic_types op2){
        Fraction q=new Fraction(0,1);
        q=(Fraction)op2; //downcast
        Fraction aux=new Fraction(0,1);
        aux=new Fraction(num * q.den + den*q.num, den*q.den);
        aux.semplifica();
        return aux;
    }
    
    
    @Override
    public arithmetic_types SUB(arithmetic_types op2){
        Fraction q=new Fraction(0,1);
        q=(Fraction)op2; //downcast
        Fraction aux=new Fraction(0,1);
        aux=new Fraction(num* q.den - den*q.num, den*q.den);
        aux.semplifica();
        return aux;
    }
    
    @Override
    public arithmetic_types  MUL(arithmetic_types op2){
        Fraction q=new Fraction(0,1);
        q=(Fraction)op2; //downcast
        Fraction aux=new Fraction(0,1);
        aux=new Fraction(num*q.num, den*q.den);
        aux.semplifica();
        return aux;
    }
    
    @Override
    public arithmetic_types  DIV(arithmetic_types op2){
        Fraction q=new Fraction(0,1);
        q=(Fraction)op2; //downcast
        Fraction aux=new Fraction(0,1);
        aux=new Fraction(num * q.den,den*q.num);
        aux.semplifica();
        return aux;
    }
    
    @Override
    public double conversion_in_real(){
        double a = (double)num;
        double b = (double)den;
        double result=a/b;
        return result;
    }
    
    public static Fraction conversion_in_fraction(String S){
    String nume="";
    String deno="1";
    boolean stop=false;
    boolean puntosuperato=false;
    boolean monkey_proof=false;
    String zero="0";
    int n=S.length();
    int it=0;
        if(S.charAt(it) == '0'){
            it++;
            while(!monkey_proof){//monkey-proof
                if(S.charAt(it)=='.')
                    monkey_proof=true;
                it++;
            }
            if(it==n)stop=true;
            while(!stop){
              if(it == n)
                  stop=true;
              else{
              nume=nume+S.charAt(it);
              it++;
              deno=deno+zero;
              }
            }
        }
        else{//*it != 0

            while(it != n){
                if(S.charAt(it) != '.'){
                    nume=nume+S.charAt(it);
                    if(puntosuperato)
                        deno=deno+zero;
                }
                else
                puntosuperato=true;

                it++;
            }
        
    }
        int numeratore=Integer.parseInt(nume);
        int denominatore=Integer.parseInt(deno);
        Fraction aux=new Fraction(numeratore,denominatore);
        aux.semplifica();
        return aux;
}
    public void semplifica(){
    boolean stop=false;
    while(!stop){
        stop=true;
    if( ((den%9)== 0) && ((num%9)== 0) ){ den=den/9; num=num/9; stop=false; }
    if( ((den%8)== 0) && ((num%8)== 0) ){ den=den/8; num=num/8; stop=false; }
    if( ((den%7)== 0) && ((num%7)== 0) ){ den=den/7; num=num/7; stop=false; }
    if( ((den%6)== 0) && ((num%6)== 0) ){ den=den/6; num=num/6; stop=false; }
    if( ((den%5)== 0) && ((num%5)== 0) ){ den=den/5; num=num/5; stop=false; }
    if( ((den%4)== 0) && ((num%4)== 0) ){ den=den/4; num=num/4; stop=false; }
    if( ((den%3)== 0) && ((num%3)== 0) ){ den=den/3; num=num/3; stop=false; }
    if( ((den%2)== 0) && ((num%2)== 0) ){ den=den/2; num=num/2; stop=false; }
    }
}
    
    public void Stampa(){
        System.out.println(num);
        System.out.println("-");
        System.out.println(den);
    }
        
    public double radice(){
    double x=this.conversion_in_real();
    double result;
    result = Math.sqrt(x);
    return result;
     }
}
