#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    int a, b, k;
    cin >> a >> b >> k;
    if (a>b) swap(a,b);

    if (k==1) {
      if (b!=a && b%a==0) {
        cout << "yes\n";
      } else {
        cout << "no\n";
      }
      continue;
    }

    int cnt=0;
    for (int i=2;i*i<=b;i++) {
      while (b%i==0) {
        b /= i; cnt++;
      }
    }
    if (b>1) cnt++;
    for (int i=2;i*i<=a;i++) {
      while (a%i==0) {
        a /= i; cnt++;
      }
    }
    if (a>1) cnt++; 

    if (k>cnt) {
      cout << "no\n";
    } else {
      cout << "yes\n";
    }
  }
}