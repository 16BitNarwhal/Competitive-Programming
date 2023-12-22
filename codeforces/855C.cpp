#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
vector<int> adj[100005];
ll n, m, x, k, dp[100005][12][3], dp2[100005][12];
void dfs(int u, int pa) { 
  for (int v : adj[u]) {
    if (v==pa) continue;
    dfs(v, u);
  } 
  // type == 0
  {
    for (int i=0;i<adj[u].size();i++) fill(dp2[i], dp2[i]+12, 0);
    dp2[0][0] = 1;
    for (int i=0;i<adj[u].size();i++) {                   // i-th child
      if (adj[u][i]==pa) continue;
      for (int cur_taken=0;cur_taken<=x;cur_taken++) {    // taken so far
        for (int take=0;take<=x-cur_taken;take++) {       // take from i-th child
          ll val = dp[adj[u][i]][take][0]+dp[adj[u][i]][take][1]+dp[adj[u][i]][take][2]; 
          dp2[i+1][cur_taken+take] = (dp2[i+1][cur_taken+take] + val * dp2[i][cur_taken])%MOD;
        }
      }
    }
    for (int i=0;i<=x;i++) {
      dp[u][i][0] = (dp2[adj[u].size()][i] * (k-1)) % MOD;
    }
  }
  // type == 1
  {
    for (int i=0;i<adj[u].size();i++) fill(dp2[i], dp2[i]+12, 0);
    dp2[0][0] = 1;
    for (int i=0;i<adj[u].size();i++) {                   // i-th child
      if (adj[u][i]==pa) continue;
      for (int cur_taken=0;cur_taken<=x;cur_taken++) {    // taken so far
        for (int take=0;take<=x-cur_taken;take++) {       // take from i-th child
          ll val = dp[adj[u][i]][take][0]; 
          dp2[i+1][cur_taken+take] = (dp2[i+1][cur_taken+take] + val * dp2[i][cur_taken])%MOD;
        }
      }
    }
    for (int i=0;i<x;i++) {
      dp[u][i+1][1] = dp2[adj[u].size()][i];
    }
  }
  // type == 2
  {
    for (int i=0;i<adj[u].size();i++) fill(dp2[i], dp2[i]+12, 0);
    dp2[0][0] = 1;
    for (int i=0;i<adj[u].size();i++) {                   // i-th child
      if (adj[u][i]==pa) continue;
      for (int cur_taken=0;cur_taken<=x;cur_taken++) {    // taken so far
        for (int take=0;take<=x-cur_taken;take++) {       // take from i-th child
          ll val = dp[adj[u][i]][take][0]+dp[adj[u][i]][take][2]; 
          dp2[i+1][cur_taken+take] = (dp2[i+1][cur_taken+take] + val * dp2[i][cur_taken])%MOD;
        }
      }
    }
    for (int i=0;i<=x;i++) {
      dp[u][i][2] = (dp2[adj[u].size()][i] * (m-k)) % MOD;
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i=1,u,v;i<n;i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin >> k >> x;
  if (n==1) {
    cout << m << '\n';
    return 0;
  }
  memset(dp, 0, sizeof dp);
  dfs(1, 0);
  ll ans=0;
  for (int i=0;i<=x;i++) { 
    ans += dp[1][i][0] + dp[1][i][1] + dp[1][i][2];
  }
  cout << ans;
}