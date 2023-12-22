#include <bits/stdc++.h>
using namespace std;
int D, I, R, dp[1001][1001];
string a, b;
int main() {
  cin >> D >> I >> R;
  cin >> a >> b;
  int N = a.length(), M = b.length();
  memset(dp, 0x3f, sizeof dp);
  for (int i=0;i<=N;i++) dp[i][0]=i*D;
  for (int i=0;i<=M;i++) dp[0][i]=i*I;
  for (int i=1;i<=N;i++) {
    for (int j=1;j<=M;j++) {
      if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
      dp[i][j] = min(dp[i][j], dp[i-1][j] + D);
      dp[i][j] = min(dp[i][j], dp[i][j-1] + I);
      dp[i][j] = min(dp[i][j], dp[i-1][j-1] + R);
    }
  }
  cout << dp[N][M] << "\n";
}