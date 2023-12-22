#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
ll req;
bool check(ll x) {
  ll n = x/3;
  ll res = n*6 + n*(n-1)*12/2;
  ll m = x%3; 
  if (m>0) res += (m-1)*2; 
  res += 4*n*m; 
  return res >= req;
}
int main() {
  int t;cin>>t;
  while (t--) {
    cin >> req;
    ll l=0, r=1e6;
    ll ans=-1;
    while (l<=r) {
      ll m = (l+r)/2; 
      if (check(m)) {
        ans = m;
        r = m-1;
      } else {
        l = m+1;
      }
    }
    assert(ans>=0);
    cout << ans << '\n';
  }
}