#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int n, m, dir[MM];
vector<pair<int,int>> bp[MM]; // bipartite
vector<int> dag[MM]; // DAG 
void dfs(int u) {
  for (auto [v, t] : bp[u]) {
    if (dir[v] == 0) {
      dir[v] = (dir[u]==1?2:1);
      dfs(v);
    } else {
      if (dir[u] == dir[v]) {
        cout << "NO\n";
        exit(0);
      }
    }
    if (dir[u]==t) {
      dag[u].push_back(v);
    } else {
      dag[v].push_back(u);
    }
  }
}
int pos[MM], p;
bool vis[MM];
void tsort(int u) {
  if (pos[u] != 0) return;
  if (vis[u]) {
    cout << "NO\n";
    exit(0);
  }
  vis[u] = true;
  for (auto v : dag[u]) {
    tsort(v);
  }
  vis[u] = false;
  pos[u] = p--;
}
int main() {
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    int t, u, v;
    cin >> t >> u >> v;
    bp[u].push_back({v,t});
    bp[v].push_back({u,t});
  }
  for (int i=1;i<=n;i++) {
    if (dir[i]==0) {
      dir[i]=1;
      dfs(i);
    }
  }
  p=n;
  for (int i=1;i<=n;i++) {
    if (pos[i]==0) {
      tsort(i);
    }
  }
  cout << "YES\n";
  for (int i=1;i<=n;i++) {
    if (dir[i]==1) cout << "L ";
    else cout << "R ";
    cout << pos[i] << '\n';
  }
}