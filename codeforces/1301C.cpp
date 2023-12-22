#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int t;cin>>t;
  while(t--) {
    ll n, m;
    cin>>n>>m;
    ll g = m+1;
    ll z = n-m; // zeros
    ll k = z/g; // zero groups
    cout << n*(n+1)/2 - k*(k+1)/2*g - (k+1)*(z%g) << '\n';
  }
}