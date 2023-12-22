#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int N, W;
ll v[101], w[101], dp[101][MM];
int main() {
  cin >> N >> W;
  for (int i=1;i<=N;i++) {
    cin >> w[i] >> v[i];
  }
  for (int i=1;i<=N;i++) {
    for (int j=0;j<=W;j++) {
      dp[i][j] = dp[i-1][j];
      if (j>=w[i]) dp[i][j] = max(dp[i-1][j-w[i]] + v[i], dp[i][j]);
    }
  }
  ll ans=0;
  for (int i=0;i<=W;i++) {
    ans = max(ans, dp[N][i]);
  }
  cout << ans << '\n';
}