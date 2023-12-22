#include <bits/stdc++.h>
using namespace std;
int a[11], b[11], c[11], d[11], dp[1001];
int main() {
  int n, m, c0, d0;
  cin >> n >> m >> c0 >> d0;
  for (int i=1;i<=m;i++) 
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  int ans=0;
  for (int j=n;j>=0;j--) {
    for (int k=0;j-c0*k>=0;k++) {
      dp[j] = max(dp[j], dp[j-c0*k] + d0*k);
      ans = max(ans, dp[j]);
    }
  }
  for (int i=1;i<=m;i++) {
    for (int j=n;j>=0;j--) {
      for (int k=0;k<=a[i]/b[i];k++) {
        if (j-c[i]*k>=0) dp[j] = max(dp[j], dp[j-c[i]*k] + d[i]*k);
        ans = max(ans, dp[j]);
      }
    }
  }
  cout << ans << '\n';
}