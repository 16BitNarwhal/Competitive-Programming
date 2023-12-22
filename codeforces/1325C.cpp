#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
typedef pair<int,int> pi;
int n, res[MM], x=0;
vector<pi> adj[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i=0,u,v;i<n-1;i++) {
    cin >> u >> v;
    adj[u].push_back({v,i});
    adj[v].push_back({u,i});
  }
  fill(res, res+n, -1);
  for (int u=1;u<=n;u++) {
    if (adj[u].size()>=3) {
      for (auto e : adj[u]) {
        int v=e.first, idx=e.second;
        res[idx] = x++;
      }
      break;
    } 
  }
  for (int i=0;i<n;i++) {
    if (res[i]==-1) res[i]=x++;
  }
  for (int i=0;i<n-1;i++) {
    cout << res[i] << '\n';
  }
}