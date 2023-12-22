import java.util.Scanner;
import java.math.BigInteger;

public class p13 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        BigInteger res = new BigInteger("0");
        for(int i=0;i<100;i++) {
            res = res.add(s.nextBigInteger());
        }
        System.out.println(res);
        
        s.close();
    }
}
