#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005];
int main() {
  int n, m;
  cin >> n >> m;
  string s1, s2;
  cin >> s1 >> s2;
  int ans=0;
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      if (s1[i-1] == s2[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 4 - 2;
      } else {
        dp[i][j] = max(0, max(dp[i-1][j], dp[i][j-1]) - 1);
      }
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans;
}