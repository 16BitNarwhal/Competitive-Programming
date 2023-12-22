#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int t=1;cin>>t;
  while(t--) {
    ll x,y;
    cin >> x >> y;
    ll ans=0;
    /**
     * k = a mod b 
     * a = kb + b (b > k)
     * k^2 < kb + k = a <= x
     * k <= sqrt(x)
     * 1 <= b <= x/k - 1
     * 1 <= k < b
     * cur = min(y, x/k - 1)
     **/
    for (ll i=1; i*i < x; i++)
      ans += max(min(y, x/i - 1)-i, 0LL);
    cout << ans << '\n';
  }
}