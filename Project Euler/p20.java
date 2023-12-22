import java.math.BigInteger;

class Main {
  public static void main(String[] args) {
    BigInteger n = new BigInteger("1");
    for(int i=1;i<=100;i++)
      n = n.multiply(new BigInteger(String.valueOf(i)));
    BigInteger sum = new BigInteger("0");
    while(n.compareTo(new BigInteger("0"))>0) {
      sum = sum.add(n.mod(new BigInteger("10")));
      n = n.divide(new BigInteger("10"));
    }
    System.out.println(sum);
  }
}

// 648