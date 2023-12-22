#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int t;cin>>t;
  while (t--) {
    ll x,y;
    cin >> x >> y;
    ll ans=0;
    for (ll i=0;i<61;i++) {
      if ((x&(1LL<<i)) && (y&(1LL<<i))==0) { 
        ll tmp = ((1LL<<i)-1) & x;
        x += (1LL<<i) - tmp;
        ans += (1LL<<i) - tmp; 
      }
    } 
    if (x != y) {
      x |= y;
      ans++;

      if (x != y) {
        cout << "-1\n"; 
        continue;
      }
    }
    cout << ans << '\n';
  }
}