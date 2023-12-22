#include <bits/stdc++.h>
using namespace std; 
int ar[102][102], dp[102][102], last[102][102];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      cin >> ar[i][j];
    }
  }
  memset(last, -1, sizeof last);
  memset(dp, -0x3f, sizeof dp);
  for (int i=0;i<=m;i++) dp[0][i]=0;
  for (int i=1;i<=n;i++) { // first i flowers
    for (int j=i;j<=m;j++) { // use first j vases
      if (dp[i][j-1] > dp[i][j]) { // don't use vase j
        dp[i][j] = max(dp[i][j], dp[i][j-1]); 
        last[i][j] = last[i][j-1]; // get vase used for flower i
      }
      if (dp[i-1][j-1] + ar[i][j] > dp[i][j]) { // use vase j
        dp[i][j] = max(dp[i][j], dp[i-1][j-1] + ar[i][j]);
        last[i][j] = j; // last[i-1][j-1] gets vase for flower i-1
      }
    }
  }
  cout << dp[n][m] << endl;
  stack<int> res;
  int i=n, j=m;
  while (i>0) {
    res.push(last[i][j]);
    j = last[i--][j]-1; // decrease i and j
  }
  while (!res.empty()) {
    cout << res.top() << " ";
    res.pop();
  }
}