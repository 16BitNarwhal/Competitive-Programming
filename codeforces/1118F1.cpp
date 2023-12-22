#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5+2; 
typedef pair<int,int> pi;
#define ff first
#define ss second
int n, ans=0, ar[MM]; 
vector<int> adj[MM];
pi tot, cnt[MM];
pi dfs(int u, int pa) {
  pi ret;
  if (ar[u]==1) ret.ff++;
  if (ar[u]==2) ret.ss++;
  for (int v : adj[u]) {
    if (v==pa) continue; 
    auto [r, b] = dfs(v, u);
    ret.ff += r;
    ret.ss += b;
    int r1 = tot.ff - r;
    int b1 = tot.ss - b;
    if ((r==0 && b1==0) || (b==0 && r1==0)) {
      ans++;
    }
  }
  return cnt[u]=ret;
}
int main() {
  cin >> n;
  for (int i=1;i<=n;i++) {
    cin >> ar[i];
    if (ar[i]==1) tot.ff++;
    if (ar[i]==2) tot.ss++;
  }
  for (int i=0;i<n-1;i++) {
    int u, v; cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1);
  cout << ans << '\n';
}