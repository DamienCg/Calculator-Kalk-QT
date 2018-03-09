package kalk;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

public class Hex  extends arithmetic_types {
    private final List<Character> op = new LinkedList<>();
    private static int base = 16;

    public Hex(String str){
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            op.add(i, ch);
        }
    }
    
     @Override
    public arithmetic_types ADD(arithmetic_types op2){
    arithmetic_types rit=new Hex("0");
    double d;
    d= this.conversion_in_real()+op2.conversion_in_real();
    int i = (int) d;
    rit=conversion_in_hex(i);
    return rit;
    }
    
    @Override
    public arithmetic_types SUB(arithmetic_types op2){
    arithmetic_types rit=new Hex("0");
    double d;
    d= this.conversion_in_real()-op2.conversion_in_real();
    int i = (int) d;
    rit=conversion_in_hex(i);
    return rit;
    }
    
    @Override
    public arithmetic_types  MUL(arithmetic_types op2){
    arithmetic_types rit=new Hex("");
    double d;
    d= this.conversion_in_real()*op2.conversion_in_real();
    int i = (int) d;
    rit=conversion_in_hex(i);
    return rit;
    }
    
    @Override
    public arithmetic_types  DIV(arithmetic_types op2){
    arithmetic_types rit=new Hex("0");
    double d;
    d= this.conversion_in_real()/op2.conversion_in_real();
    int i = (int) d;
    rit=conversion_in_hex(i);
    return rit;
    }
    
    @Override
    public double conversion_in_real(){
    int size=op.size()-1;
    int op1=0; double tot=0;
     ListIterator<Character> litr = op.listIterator();
        while(litr.hasNext()){
             op1=conerti_char_in_int(litr.next());
             tot=tot +(op1*(Math.pow(base,size)));
             size=size-1;
    }
        return tot;
}
    public int conerti_char_in_int(Character x){
    int rit=0;
    switch (x){
    case 0:
    rit=0;
    break;
    case '1':
    rit=1;
    break;
    case '2':
    rit=2;
    break;
    case '3':
    rit=3;
    break;
    case '4':
    rit=4;
    break;
    case '5':
    rit=5;
    break;
    case '6':
    rit=6;
    break;
    case '7':
    rit=7;
    break;
    case '8':
    rit=8;
    break;
    case '9':
    rit=9;
    break;
    case 'A':
    rit=10;
    break;
    case 'B':
    rit=11;
    break;
    case 'C':
    rit=12;
    break;
    case 'D':
    rit=13;
    break;
    case 'E':
    rit=14;
    break;
    case 'F':
    rit=15;
    break;
    case 'a':
    rit=10;
    break;
    case 'b':
    rit=11;
    break;
    case 'c':
    rit=12;
    break;
    case 'd':
    rit=13;
    break;
    case 'e':
    rit=14;
    break;
    case 'f':
    rit=15;
    break;
}
return rit;
    }
    
    public static Hex conversion_in_hex(int x){
     Hex aux=new Hex(""); 
    if(x==0){aux.op.add(0,'0'); return aux;}
    while(x>0){
      int resto=x%base;
      Character temp=coverti_int_in_char_base16(resto);
      aux.op.add(0,temp);
      x=x/base;
    }
    return aux;
    }
    
    public static Character coverti_int_in_char_base16(int x){
          Character rit ='0';
    switch (x){
    case 0:
        rit ='0';
    break;
    case 1:
        rit ='1';
    break;
    case 2:
        rit ='2';
    break;
    case 3:
        rit ='3';
    break;
    case 4:
        rit ='4';
    break;
    case 5:
        rit = '5';
    break;
    case 6:
        rit = '6';
    break;
    case 7:
        rit = '7';
    break;
    case 8:
        rit = '8';
    break;
}
return rit;
}
    
    public void Stampa(){
        System.out.println(op.toString());
    }
        
    public double radice(){
    double x=this.conversion_in_real();
    double result;
    result = Math.sqrt(x);
    return result;
     }

 
}
