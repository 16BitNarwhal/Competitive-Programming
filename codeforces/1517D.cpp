#include <bits/stdc++.h>
using namespace std;
int n, m, k, cst[2][505][505];
int dp[505][505][11];
int solve(int i, int j, int k) {
  if (k==0) return 0;
  if (dp[i][j][k] != -1) return dp[i][j][k];
  int ans = 1e9;
  if (i<n-1) ans = min(ans, solve(i+1, j, k-1) + cst[1][i][j]);
  if (i>0) ans = min(ans, solve(i-1, j, k-1) + cst[1][i-1][j]);
  if (j<m-1) ans = min(ans, solve(i, j+1, k-1) + cst[0][i][j]);
  if (j>0) ans = min(ans, solve(i, j-1, k-1) + cst[0][i][j-1]);
  return dp[i][j][k] = ans;
}
int main() {
  cin >> n >> m >> k;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m-1;j++) 
      cin >> cst[0][i][j];
  }
  for (int i=0;i<n-1;i++) {
    for (int j=0;j<m;j++) 
      cin >> cst[1][i][j];
  }
  if (k & 1) {
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) cout << "-1 ";
      cout << '\n';
    }
    return 0;
  }
  memset(dp, -1, sizeof dp);
  k /= 2;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++)
      cout << 2*solve(i, j, k) << " ";
    cout << '\n';
  }
}
 