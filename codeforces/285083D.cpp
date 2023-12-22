#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
struct edge {
  int v, w;
};
int n, m, d, pa[MM];
vector<edge> adj[MM];
bool vis[MM];
int dis[MM];
bool bfs(int mx) {
  fill(vis, vis+n+1, false);
  fill(dis, dis+n+1, 0);
  queue<int> q;
  q.push(1); vis[1]=true;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (dis[u]>=d) continue;
    for (edge e : adj[u]) {
      int v=e.v, w=e.w;
      if (vis[v] || w>mx) continue;
      vis[v]=true;
      dis[v]=dis[u]+1;
      pa[v]=u;
      q.push(v);
    }
  }
  return vis[n];
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> d;
  for (int i=0;i<m;i++) {
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
  }   
  int l=0,r=1e9,ans=-1;
  while (l<=r) {
    int m = l + (r-l)/2;
    fill(vis, vis+n+1, false);
    if (bfs(m)) {
      ans = m; 
      r = m-1;
    } else {
      l = m+1;
    }
  }
  if (ans==-1) {
    cout << "-1\n";
    return 0;
  }
  int u=n,cnt=0;
  stack<int> s;
  while (u!=1) {
    s.push(u);
    u = pa[u]; 
  }
  cout << s.size() << '\n'; 
  cout << "1 ";
  while (!s.empty()) {
    int x = s.top(); s.pop();
    cout << x << ' ';
  }
}