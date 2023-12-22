#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
int t[2002];
ll cst[2002], dp[2002][2002];
int main() {
  int n;cin>>n;
  for (int i=0;i<n;i++) {
    cin >> t[i] >> cst[i];
  }
  for (int i=0;i<=n;i++) fill(dp[i], dp[i]+2002, 1e18);
  dp[0][0] = 0;
  for (int i=0;i<n;i++) {
    for (int j=0;j<=2000;j++) {
      int k = min(j+t[i]+1, 2000);
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
      dp[i+1][k] = min(dp[i+1][k], dp[i][j]+cst[i]);
    }
  }
  ll ans=1e18;
  for (int i=n;i<=2000;i++) 
    ans = min(ans, dp[n][i]);
  cout << ans << '\n';
}

/*

dp[i-th item][t total time] = cst

steal item:
+0 cost
+0 time
dp[i+1][j] = min(dp[i+1][j], dp[i][j])

buy item:
+c cost
+t+1 time
dp[i+1][j+t] = min(dp[i+1][j+t], dp[i][j]+cst)

*/