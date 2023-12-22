#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
ll n, a, b, x[MM], suf[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    cin >> n >> a >> b;
    for (int i=1;i<=n;i++) cin >> x[i];
    suf[n+1] = 0;
    for (int i=n;i>=1;i--) suf[i] = suf[i+1] + x[i];
    ll ans = 1e18;
    for (int i=0;i<=n;i++) {
      ll lft = a*x[i] + b*x[i];
      ll rht = b*(suf[i+1] - x[i]*(n-i)); 
      ans = min(ans, lft + rht);
    }
    cout << ans << '\n';
  }
}