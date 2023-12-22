#include <Bits/stdc++.h>
using namespace std;
int m, n, dp[33][33], B[33], R[33];
int solve(int r, int c) {
  if (r==m) return 1;
  if (dp[r][c] != -1) return dp[r][c];
  dp[r][c] = 0;
  for (int i=B[r]+1;i<=min(R[r], c);i++) {
    dp[r][c] += solve(r+1, i);
  }
  return dp[r][c];
}
int main() {
  cin >> m >> n;
  for (int i=0;i<m;i++) {
    string s;cin>>s;
    R[i]=n;
    B[i]=-1;
    for (int j=0;j<n;j++) {
      if (s[j]=='B') {
        B[i] = max(B[i], j);
      } else if (s[j]=='R') {
        R[i] = min(R[i], j);
      }
    }
  }
  for (int i=0;i<m;i++) cout << R[i] << ' ';
  cout << '\n';
  for (int i=0;i<m;i++) cout << B[i] << ' ';
  cout << '\n';
  cout << "***\n";
  memset(dp, -1, sizeof dp);
  for (int i=0;i<m;i++) {
    for (int j=0;j<=n;j++) {
      cout << solve(i, j) << ' ';
    }
    cout << '\n';
  }
}