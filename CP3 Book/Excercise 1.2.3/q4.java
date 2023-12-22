import java.util.Scanner;
import java.math.BigInteger;

public class q4 {
    BigInteger[] merge(BigInteger[] ar, int l, int r) {
        int m = (l+r)/2, n1 = m-l+1, n2 = r-m;
        BigInteger[] left = new BigInteger[n1],
        right = new BigInteger[n2];
        for(int i=0;i<n1;i++)
            left[i] = ar[i + l];
        for(int i=0;i<n2;i++) 
            right[i] = ar[i + m + 1];
        int i=0, j=0, k=l;
        while(i<n1 && j<n2) {
            if(left[i].compareTo(right[j]) < 0) {
                ar[k] = left[i];
                i++;
            } else {
                ar[k] = right[j];
                j++;
            }
            k++;
        }
        while(i<n1) {
            ar[k] = left[i];
            i++; k++;
        }
        while(j<n2) {
            ar[k] = right[j];
            j++; k++;
        }
        return ar;
    }
    BigInteger[] mergesort(BigInteger[] ar, int l, int r) {
        if(l < r) {
            int m = (l+r) /2;
            mergesort(ar, l, m);
            mergesort(ar, m+1, r);
            merge(ar, l, r);
        }
        return ar;
    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        BigInteger[] ar = new BigInteger[n];
        for(int i=0;i<n;i++) {
            ar[i] = s.nextBigInteger();
        }
        q4 ob = new q4();
        ob.mergesort(ar, 0, n-1);
        for(int i=0;i<n;i++) {
            System.out.print(ar[i] + " ");
        }
        System.out.println();
        s.close();
    }
}