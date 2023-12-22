#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll n, p; cin >> n >> p; 
  for (int i=1;i<32;i++) {
    ll x = n - (p * i);
    bitset<32> b(x);
    if (x>0 && i<=x && b.count() <= i) { 
      cout << i << '\n';
      return 0;
    }
  }
  cout << "-1\n";
}