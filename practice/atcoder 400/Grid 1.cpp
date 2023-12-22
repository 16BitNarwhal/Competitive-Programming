#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int ar[1010][1010], dp[1010][1010];
int main() {
  int h, w;
  cin >> h >> w;
  for (int i=1;i<=h;i++) {
    for (int j=1;j<=w;j++) {
      char c;cin>>c;
      ar[i][j] = c=='#'?1:0;
    }
  }
  dp[1][1] = (ar[1][1]==0);
  for (int i=1;i<=h;i++) {
    for (int j=1;j<=w;j++) {
      if (ar[i][j]) continue;
      if (i==1 && j==1) continue;
      dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
    }
  }
  cout << dp[h][w] << '\n';
}