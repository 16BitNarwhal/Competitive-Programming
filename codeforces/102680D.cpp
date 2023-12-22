#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x) {
  for (int i=2;i*i<=x;i++ ){
    if (x%i==0) return false;
  }
  return true;
}
int main() {
  int t;cin>>t;
  while (t--) {
    int q;cin>>q;
    if (q==1) {
      cout << "Neither\n";
    } else if (isPrime(q)) {
      cout << "Prime\n";
    } else {
      cout << "Composite\n";
    }
  }
}