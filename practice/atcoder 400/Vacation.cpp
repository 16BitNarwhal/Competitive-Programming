// https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n, ar[MM][3], dp[MM][3];
int main() {
  cin >> n;
  for (int i=1;i<=n;i++) 
    cin >> ar[i][0] >> ar[i][1] >> ar[i][2];
  for (int i=1;i<=n;i++) {
    for (int j=0;j<3;j++) {
      for (int k=0;k<3;k++)
        if (j != k) dp[i][j] = max(dp[i][j], dp[i-1][k] + ar[i][j]);
    }
  }
  cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << '\n';
}