#include <bits/stdc++.h>
using namespace std;
const int MM = 1010, MOD = 998244353;
const int BB = 0, BW = 1, WB = 2, WW = 3;
// dp[i column][j comps][k mask (previous state)]
int n,k,dp[MM][2*MM][4];
int get(int mask, int nmask) {
  switch(mask) {
    case BB:
      if (nmask==BB) return 0;
      else return 1;
    case WW:
      if (nmask==WW) return 0;
      else return 1;
    case BW:
      if (nmask==WB) return 2;
      else return 0;
    case WB:
      if (nmask==BW) return 2;
      else return 0;
  }
}
int main() {
  cin >> n >> k;  
  memset(dp, 0, sizeof dp);
  dp[1][1][BB] = dp[1][1][WW] = dp[1][2][BW] = dp[1][2][WB] = 1; 
  for (int i=1;i<n;i++) {
    for (int j=0;j<=k;j++) {
      for (int mask=0;mask<4;mask++) {
        for (int nmask=0;nmask<4;nmask++) { // new mask
          int x = j+get(mask, nmask);
          dp[i+1][x][nmask] = (dp[i+1][x][nmask]+dp[i][j][mask]) % MOD;
        }
      } 
    } 
  }
  int ans=0;
  for (int i=0;i<4;i++) 
    ans = (ans + dp[n][k][i]) % MOD;
  cout << ans << '\n';
}