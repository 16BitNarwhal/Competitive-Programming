#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e5+2, mod = 998244353;
int n,q,pa[MM],e[2*MM],e2[MM],h[MM],ptr=0,st[2*MM][20],st2[2*MM][20];
vector<int> adj[MM];
ll ans, pre[MM][51];
void dfs(int u, int p, int d) {
  pre[u][0] = 1; pa[u] = p; h[u] = d;
  for (int i=1;i<=50;i++)
    pre[u][i] = (pre[u][i-1] * d) % mod;
  for (int i=1;i<=50;i++)
    pre[u][i] = (pre[u][i] + pre[p][i]) % mod;

  e2[u] = ptr;
  e[ptr++] = u;
  for (int v : adj[u]) {
    if (v==p) continue;
    dfs(v, u, d+1);
    e[ptr++] = u;
  }
} 
void rmq() {
  for (int i=0;i<ptr;i++) {
    st[i][0] = h[e[i]];
    st2[i][0] = e[i];
  }
  for (int j=1;j<20;j++) {
    for (int i=0;i+(1<<j)<=ptr;i++) {
      if (st[i][j-1] < st[i+(1<<(j-1))][j-1]) {
        st[i][j] = st[i][j-1];
        st2[i][j] = st2[i][j-1];
      } else {
        st[i][j] = st[i+(1<<(j-1))][j-1];
        st2[i][j] = st2[i+(1<<(j-1))][j-1];
      }
    }
  }
}
int lca(int l, int r) {
  l = e2[l]; r = e2[r];
  if (l>r) swap(l, r);
  int j = log2(r-l+1);
  if (st[l][j] < st[r-(1<<j)+1][j]) {
    return st2[l][j];
  } else {
    return st2[r-(1<<j)+1][j]; 
  }
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i=1;i<n;i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i=1;i<=50;i++) pre[0][i]=0;
  dfs(1, 0, 0); 
  rmq();

  cin >> q;
  while (q--) { 
    int u, v, k;
    cin>>u>>v>>k; 
    int l = lca(u, v); 
    ans = pre[u][k] + pre[v][k] - pre[pa[l]][k] - pre[l][k];
    while (ans<0) ans+=mod;
    ans %= mod;
    cout << ans << '\n';
  }
}