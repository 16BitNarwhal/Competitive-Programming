#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2; 
int n;
bool ok[MM];
ll cst[MM], dp[MM][3];
vector<int> adj[MM];
void dfs(int u, int pa=0) {
  ll sum0=0, sum1=0;
  ll mn0=2e9, mn1=2e9;
  for (int v : adj[u]) {
    if (v==pa) continue;
    dfs(v, u);
    sum0 += dp[v][0];
    sum1 += dp[v][1];
    mn0 = min(mn0, -dp[v][0] + dp[v][2]);
    mn1 = min(mn1, -dp[v][1] + dp[v][2]);
  }
  if (ok[u]) {
    dp[u][0] = sum1;
    dp[u][1] = sum1;
    dp[u][2] = sum0 + cst[u];
  } else {
    dp[u][0] = min(sum0 + cst[u], sum1);
    dp[u][1] = sum1 + mn1;
    dp[u][2] = sum0 + cst[u] + mn0;
  }
  dp[u][1] = min(dp[u][1], dp[u][2]);
  dp[u][0] = min(dp[u][0], dp[u][1]);
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i=0;i<n-1;i++) {
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i=1;i<=n;i++) {
    char c;cin>>c; 
    ok[i] = (c=='Y');
  }
  for (int i=1;i<=n;i++) 
    cin >> cst[i];
  
  dfs(1);
  cout << dp[1][1] << '\n';
}

/*

dp[i][0] = must be influenced by parent
dp[i][1] = nothing particular with parent
dp[i][2] = must influence parent

sum0 = must influence all children
sum1 = nothing particular with children

mn0 = influenced by 1 child in sum0
mn1 = influenced by 1 child in sum1

if Y:
 dp[i][0] = sum1
 dp[i][1] = sum1
 dp[i][2] = sum0 + cst

else:
 dp[i][0] = sum0 + cst or sum1
 dp[i][1] = sum1 + mn1
 dp[i][2] = sum0 + cst + mn0

dp[i][1] = min(dp[i][1], dp[i][2])
dp[i][0] = min(dp[i][0], dp[i][1])

*/