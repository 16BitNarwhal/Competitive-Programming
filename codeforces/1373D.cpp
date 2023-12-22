#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
int n, ar[MM];
ll dp[MM][3];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> ar[i];
    for (int i=0;i<=n;i++) 
      dp[i][0] = dp[i][1] = dp[i][2] = 0;
    for (int i=0;i<n;i++) {
      dp[i+1][0] = max(dp[i+1][0], dp[i][0] + (i&1?0:ar[i]));
      dp[i+2][1] = max(dp[i+2][1], max(dp[i][0], dp[i][1]) + (i&1?ar[i]:ar[i+1]));
      dp[i+1][2] = max(dp[i+1][2], max(max(dp[i][0], dp[i][1]), dp[i][2])
                                      + (i&1?0:ar[i]));
    }
    cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << '\n';
  }
}