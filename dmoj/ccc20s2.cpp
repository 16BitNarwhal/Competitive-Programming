#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int MM = 1001, MX = 1e6+1;
int N, M, ar[MM][MM];
vector<int> adj[MX];
bool vis[MX];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
  for (int i=1;i<=N;i++) {
    for (int j=1;j<=M;j++) {
      cin >> ar[i][j];
      adj[i*j].push_back(ar[i][j]);
    }
  }

  queue<int> bfs;
  bfs.push(ar[1][1]);
  vis[ar[1][1]] = 1;
  while (!bfs.empty()) {
    int u = bfs.front(); bfs.pop();
    for (int v : adj[u]) {
      if (!vis[v]) {
        bfs.push(v);
        vis[v] = 1;
      }
    }
  }
  cout << (vis[N*M] ? "yes" : "no") << '\n';
} 