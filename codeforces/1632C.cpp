#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6;
map<int,int> dp[MM];
int main() {
  int t;cin>>t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    memset(dp, 0x3f, sizeof dp);
    dp[a][b] = 0;
    for (int i=a;i<=b;i++) {
      for (int j=b;j<=2*b;j++) {
        dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
        dp[i|j][j] = min(dp[i|j][j], dp[i][j]+1);
        dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);
      }
    }
    int ans=1e9;
    for (int i=b;i<=2*b;i++) {
      ans = min(ans, dp[i][i]);
    }
    cout << ans << '\n';
  }
}