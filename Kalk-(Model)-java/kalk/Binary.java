
package kalk;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

public class Binary extends arithmetic_types {
    private final List<Character> op = new LinkedList<>();
    private static int base = 2;
    
    public Binary(String str){
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            op.add(i, ch);
        }
    }
     @Override
    public arithmetic_types ADD(arithmetic_types op2){
    arithmetic_types rit=new Binary("0");
    double d;
    d= this.conversion_in_real()+op2.conversion_in_real();
    int i = (int) d;
    rit=conversion_in_binary(i);
    return rit;
    }
    
    @Override
    public arithmetic_types SUB(arithmetic_types op2){
    arithmetic_types rit=new Binary("0");
    double d;
    d= this.conversion_in_real()-op2.conversion_in_real();
    int i = (int) d;
    rit=conversion_in_binary(i);
    return rit;
    }
    
    @Override
    public arithmetic_types  MUL(arithmetic_types op2){
    arithmetic_types rit=new Binary("0");
    double d;
    d= this.conversion_in_real()*op2.conversion_in_real();
    int i = (int) d;
    rit=conversion_in_binary(i);
    return rit;
    }
    
    @Override
    public arithmetic_types  DIV(arithmetic_types op2){
    arithmetic_types rit=new Binary("0");
    double d;
    d= this.conversion_in_real()/op2.conversion_in_real();
    int i = (int) d;
    rit=conversion_in_binary(i);
    return rit;
    }
    
    @Override
    public double conversion_in_real(){
    int n=op.size()-1;
    double x=0;
        ListIterator<Character> litr = op.listIterator();
        while(litr.hasNext()){
             if(litr.next() == '1')
              x=x+Math.pow(base,n);
        n--;
    }
    return x;
    }
    
    public static Binary conversion_in_binary(int x){
    if(x == 0)
        return new Binary("0");
    if(x == 1)
        return new Binary("01");
    
    String str= ""; String zero="0"; String uno="1";
    while(x != 0){
        if( (x%base) == 0)
            str=zero+str;
            else
            str=uno+str;
        x=x/base;
    }
    return new Binary(str);
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

 
}/*END CLASS*/
