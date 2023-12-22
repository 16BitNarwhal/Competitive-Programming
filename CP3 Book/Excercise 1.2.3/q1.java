import java.util.Scanner;
import java.util.Formatter;
import java.math.BigDecimal;

public class q1 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Formatter f = new Formatter();
        BigDecimal x = s.nextBigDecimal();
        BigDecimal help = new BigDecimal("10");
        if(x == new BigDecimal("0"))
            System.out.print("s");
        for(int i=0;i<2;i++) {
            if(x.compareTo(help) < 0)
                System.out.print("s");
            help = help.multiply(new BigDecimal("10"));
        }
        System.out.print(x);
        BigDecimal y = new BigDecimal(x.toBigInteger().toString());
        x = x.subtract(y);
        if(x.compareTo(new BigDecimal("0")) == 0)
            System.out.print(".");
        for(int i=0;i<3;i++) {
            y = new BigDecimal(x.toBigInteger().toString());
            x = x.subtract(y);
            x = x.multiply(new BigDecimal("10"));
            if(x.compareTo(BigDecimal.ONE) < 0) {
                System.out.print("s");
            }
        }
        System.out.println();
        
        s.close();
        f.close();
    }
}
