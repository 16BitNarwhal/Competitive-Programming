#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int t;cin>>t;
  while (t--) {
    ll n; cin >> n;
    ll x = n;
    while (x%2==0) x/=2;
    if (x==1) cout << "-1\n";
    else cout << min(x, n/x*2) << '\n';
  }
}