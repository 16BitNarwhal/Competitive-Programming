#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 202*202;
ll cnt[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    ll a, b, q;
    cin >> a >> b >> q;
    ll n = a*b;
    for (int i=0;i<n;i++) {
      cnt[i] = (i%a)%b != (i%b)%a; 
      if (i) cnt[i] += cnt[i-1];
    } 
    while (q--) {
      ll l, r;
      cin >> l >> r;
      l--;
      ll x = r/n - l/n;
      ll ans = x*cnt[n-1] - cnt[l%n] + cnt[r%n];
      cout << ans << ' ';
    }
    cout << '\n';
  }
}