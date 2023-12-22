import java.math.BigInteger;

public class p16 {
    public static void main(String[] args) {
        int b = 1000;
        BigInteger x = new BigInteger("1"), 
                    a = new BigInteger("2");
        while (b > 0) {
            if(b%2==1)
                x = x.multiply(a);
            a = a.multiply(a);
            b >>= 1;
        }
        BigInteger sum = new BigInteger("0");
        while(x.compareTo(new BigInteger("1"))>=0) {
            sum = sum.add(x.mod(new BigInteger("10")));
            x = x.divide(new BigInteger("10"));
        }
        System.out.println(sum);
    }
}
