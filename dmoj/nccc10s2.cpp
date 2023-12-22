#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+2;
bool grid[26][26];
vector<int> adj[26];
int dis[26], ans;
int dfs(int u) {
  dis[u]=0;
  for (int v : adj[u]) {
    if (dis[v]==-1) dfs(v);
    dis[u] = max(dis[u], dis[v]+1);
  }
  return dis[u];
}
int main() {
  int N, K;
  cin >> N >> K;
  memset(grid, true, sizeof grid);
  for (int i=0;i<N;i++) {
    string s="";
    for (int j=0;j<K;j++) {
      char x;cin>>x;
      s += x;
      for (char y : s) {
        // x not before y
        grid[x-'A'][y-'A'] = false;
      }
    }
  }
  for (int i=0;i<K;i++) {
    for (int j=0;j<K;j++) {
      if (grid[i][j]) adj[i].push_back(j);
    }
  }
  ans=0;
  for (int i=0;i<K;i++) {
    memset(dis, -1, sizeof dis);
    ans = max(ans, dfs(i));
  }
  cout << ans+1 << '\n';
}