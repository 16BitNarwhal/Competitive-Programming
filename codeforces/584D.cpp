#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
  for (int i=2;i*i<=x;i++) {
    if (x%i==0) return false;
  }
  return true;
}

int main() {
  int n;cin>>n;
  for (int i=n;i>=0;i--) {
    if (isPrime(i)) {
      if (i==n) {
        cout << 1 << '\n' << i << '\n';
        return 0;
      }
      int d = n-i;
      if (isPrime(d)) {
        cout << 2 << '\n' << i << ' ' << d << '\n';
        return 0;
      }
      for (int j=2;j<d;j++) {
        if (isPrime(j) && isPrime(d-j)) {
          cout << 3 << '\n' << i << ' ' << j << ' ' << d-j << '\n';
          return 0;
        }
      }
    }
  }
}