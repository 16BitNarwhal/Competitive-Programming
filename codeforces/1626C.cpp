#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k[110], h[110];
ll x[110];
ll sum(ll x) {
  return x*(x+1)/2;
}
int main() {
  int t;cin>>t;
  while (t--) {
    cin >> n;
    for (int i=1;i<=n;i++) cin >> k[i];
    for (int i=1;i<=n;i++) cin >> h[i];
    for (int i=n-1;i>=0;i--) {
      h[i] = max(h[i], h[i+1] - (k[i+1] - k[i]));
    }
    ll ans=0;
    for (int i=1;i<=n;i++) {
      int d = k[i] - k[i-1];
      if (d >= h[i]) {
        ans += sum(h[i]);
      } else {
        h[i] = h[i-1] + d;
        ans += sum(h[i]) - sum(h[i-1]);
      }
    }
    cout << ans << '\n';
  }
}
