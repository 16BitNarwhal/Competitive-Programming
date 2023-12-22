#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5e5+5, mod = 998244353;
ll ar[MM], dp[MM][2];
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin >> ar[i];
    for (int i=0;i<=n;i++) 
      for (int j=0;j<3;j++) dp[i][j] = 0;
    dp[0][0] = 1;
    for (int i=1;i<=n;i++) {
      int x = ar[i];
      dp[x+1][0] = (dp[x+1][0] + dp[x+1][0] + dp[x][0]) % mod;
      if (x>0) dp[x-1][1] = (dp[x-1][1] + dp[x-1][0] + dp[x-1][1]) % mod;
      dp[x+1][1] = (dp[x+1][1] + dp[x+1][1]) % mod;
    }
    ll ans = -1; // remove dp[0][0]
    for (int i=0;i<=n;i++) {
      for (int j=0;j<2;j++) {
        ans = (ans + dp[i][j]) % mod;
      }
    }
    cout << ans << '\n';
  }
}