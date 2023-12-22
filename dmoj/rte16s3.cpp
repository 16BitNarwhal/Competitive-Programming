#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
const int MM = 6001;
struct ed { ui v, w; };
ui N, Q, dis[MM][MM];
vector<ed> adj[MM];
void dfs(int u, int start, ui d=0, int pa=-1) {
  dis[u][start] = d;
  for (ed e : adj[u]) {
    if (e.v == pa) continue;
    dfs(e.v, start, d+e.w, u);
  }
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (ui i=1,u,v,w;i<N;i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  for (int i=0;i<N;i++) {
    dfs(i, i);
  }
  cin >> Q;
  while (Q--) {
    int a,b;cin>>a>>b;
    cout << dis[a][b] << '\n';
  }
}