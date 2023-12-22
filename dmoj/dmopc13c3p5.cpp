#include <bits/stdc++.h>
using namespace std;
int M, U, R, V[151], T[151], F[151], dp[301][101][151];
int main() {
  cin >> M >> U >> R;
  for (int i=1;i<=R;i++) {
    cin >> V[i] >> T[i] >> F[i];
  }
  memset(dp, 0, sizeof dp); 
  for (int i=1;i<=M;i++) {
    for (int j=1;j<=U;j++) {
      for (int k=1;k<=R;k++) {
        dp[i][j][k] = dp[i][j][k-1];
        if (i-T[k]>=0 && j-F[k]>=0)
          dp[i][j][k] = max(dp[i][j][k], dp[i-T[k]][j-F[k]][k-1] + V[k]); 
      }
    }
  }
  cout << dp[M][U][R] << '\n';
}