#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
ll dp[505][505], x[505], s[505];
int main() {
  int n, l, k;
  cin >> n >> l >> k;
  for (int i=0;i<n;i++) cin >> x[i];
  x[n] = l;
  for (int i=0;i<n;i++) cin >> s[i];
  for (int i=0;i<=n;i++) fill(dp[i], dp[i]+k+1, inf);
  dp[0][0] = 0;
  for (int i=1;i<=n;i++) {
    for (int take=0;take<=k;take++) {
      if (take>i) continue;
      dp[i][take] = dp[i-1][take] + (x[i]-x[i-1]) * s[i-1];
      for (int j=0;j<i;j++) {
        if (take-(i-j-1) < 0) continue;
        dp[i][take] = min(dp[i][take], dp[j][take-(i-j-1)] + (x[i]-x[j]) * s[j]);
      }
    }
  }
  ll ans=inf;
  for (int i=0;i<=k;i++) {
    ans = min(ans, dp[n][i]);
  }
  cout << ans;
}