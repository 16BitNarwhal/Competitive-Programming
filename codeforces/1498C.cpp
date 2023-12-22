#include <bits/stdc++.h>
using namespace std;
const int MM = 1001, mod=1e9+7;
int n, k, dp[MM][MM][2];
int rec(int cur, int k, int dir) {
  if (k==1) return 1;
  if (dp[cur][k][dir] != -1) 
    return dp[cur][k][dir];
  
  int ans=2;
  if (dir==1) {
    if (cur < n) 
      ans += rec(cur+1, k, 1) - 1;
    ans %= mod;

    if (cur > 1)
      ans += rec(cur-1, k-1, 0) - 1;
    ans %= mod;
  } else {
    if (cur > 1) 
      ans += rec(cur-1, k, 0) - 1;
    ans %= mod;

    if (cur < n)
      ans += rec(cur+1, k-1, 1) - 1;
    ans %= mod;
  }
  return dp[cur][k][dir] = ans;
}
int main() {
  int t;cin>>t;
  while(t--) {
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    cout << rec(1, k, 1) << '\n';
  }
}