#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return (b==0?a:gcd(b,a%b)); }
int main() { 
  int t;cin>>t;
  while (t--) {
    int a;cin>>a;
    int g = gcd(180, a);
    int n = 180 / g; 
    int k = a * n / 180;
    if (k+1==n) k*=2, n*=2;
    cout << n << '\n';
  }
}