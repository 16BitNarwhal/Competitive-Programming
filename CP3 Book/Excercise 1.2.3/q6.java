import java.util.Scanner;
import java.math.BigInteger;

public class q6 {
    
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        BigInteger[] ar = new BigInteger[n];
        for(int i=0;i<n;i++) {
            ar[i] = s.nextBigInteger();
        }
        BigInteger x = s.nextBigInteger();
        int l = 0, r = n, m = (l+r)/2;
        while(l<r) {
            m = (l+r)/2;
            if(ar[m].compareTo(x) == 0) break;
            else if(ar[m].compareTo(x) < 0)
                l = m+1;
            else
                r = m-1;
        }
        if(ar[m].compareTo(x) == 0)
            System.out.println("Yes " + m);
        else
            System.out.println("No ");
        s.close();
    }
}