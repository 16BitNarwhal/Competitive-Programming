#include <bits/stdc++.h>
using namespace std;
const int MM = 1002;
int N, M, dp[MM][MM];
string a, b;
int main() {
  cin >> N >> M >> a >> b;
  for (int i=0;i<=N;i++) 
    dp[i][0] = (i+2)/3;
  for (int i=0;i<=M;i++)
    dp[0][i] = (i+2)/3;
  for (int i=1;i<=N;i++) {
    for (int j=1;j<=M;j++) {
      int x = (a[i-1]!=b[j-1]);
      dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+x);
      if (i>=2) dp[i][j] = min(dp[i][j], dp[i-2][j]+1);
      if (j>=2) dp[i][j] = min(dp[i][j], dp[i][j-2]+1);
      if (i>=3) dp[i][j] = min(dp[i][j], dp[i-3][j]+1);
      if (j>=3) dp[i][j] = min(dp[i][j], dp[i][j-3]+1); 
    }
  }
  cout << dp[N][M] << '\n';
}