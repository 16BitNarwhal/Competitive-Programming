#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[101], b[101];
bitset<10010> dp;
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    ll ans=0, tot=0;
    for (int i=0;i<n;i++) {
      cin >> a[i];
      ans += a[i] * a[i];
      tot += a[i];
    }
    for (int i=0;i<n;i++) {
      cin >> b[i];
      ans += b[i] * b[i];
      tot += b[i];
    }
    ans *= (n-2);
    dp.reset();
    dp[0] = 1;
    for (int i=0;i<n;i++) 
      dp = (dp << a[i]) | (dp << b[i]);
    ll mn=1e18;
    for (int i=0;i<=10000;i++) {
      if (dp[i]) {
        ll sa = i, sb = tot - i;
        mn = min(mn, sa*sa + sb*sb);
      }
    }
    ans += mn;
    cout << ans << '\n';
  }
}