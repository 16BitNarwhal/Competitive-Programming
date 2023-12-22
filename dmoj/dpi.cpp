#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int n;
ld p[3003], dp[3003][3003];
// dp[index][heads]
int main() {
  cin >> n;
  for (int i=1;i<=n;i++)
    cin >> p[i];
  dp[0][0] = 1;
  for (int i=1;i<=n;i++) {
    for (int j=0;j<=n;j++) {
      dp[i][j+1] += dp[i-1][j] * p[i]; // increase head
      dp[i][j] += dp[i-1][j] * (1-p[i]); // dont increase head
    }
  }
  ld ans=0;
  for (int i=n/2+1;i<=n;i++) {
    ans += dp[n][i];
  }
  cout << fixed << setprecision(10) << ans << endl;
}