
package kalk;
/**
 * @author Damien Ciagola
 */
public class Use {
    
    public static void main(String[] args) {
        // Binary Part
        
        arithmetic_types x=new Binary("101110");
        arithmetic_types y=new Binary("101101");
        System.out.println(x.conversion_in_real());
        int num=46;
        x=Binary.conversion_in_binary(num);
        x=x.ADD(y);
        Binary z=new Binary("0");
        z = (Binary)x; // downcast
        z.Stampa();
        System.out.println(z.radice());
        
         //Hex Part
        /*
        arithmetic_types x=new Hex("ADad5");
        arithmetic_types y=new Hex("Cfe13");
        System.out.println(x.conversion_in_real());
        int num=118;
        x=Hex.conversion_in_hex(num);
        x=x.SUB(y);
        Hex z=new Hex("");
        z = (Hex)x; // downcast
        z.Stampa();
        System.out.println(z.radice());
        */
        
        //Octal Part
        /*
        arithmetic_types x=new Octal("81736524");
        arithmetic_types y=new Octal("183613");
        System.out.println(y.conversion_in_real());
        int num=720;
        x=Octal.conversion_in_oct(num);
        x=x.MUL(y);
        Octal z=new Octal("");
        z = (Octal)x; // downcast
        z.Stampa();
        System.out.println(z.radice());
        */
        
    }
    
}
