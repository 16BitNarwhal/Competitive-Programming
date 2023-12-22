#include <bits/stdc++.h>
using namespace std;
set<int> adj[51];
int dis[51];
void join(int u, int v) {
  adj[u].insert(v);
  adj[v].insert(u);
}
void init() {
  join(2,6);
  join(1,6);
  join(6,7);
  join(7,8);
  join(8,9);
  join(9,12);
  join(9,10);
  join(10,11);
  join(11,12);
  join(3,6);
  join(4,6);
  join(5,6);
  join(3,4);
  join(4,5);
  join(3,5);
  join(3,15);
  join(15,13);
  join(12,13);
  join(13,14);
  join(16,18);
  join(18,17);
  join(16,17);
}
int main() {
  init();
  int x, y;
  char op;
  while (1) {
    cin >> op;
    if (op=='i') {
      cin >> x >> y;
      join(x,y);
    } else if (op=='d') {
      cin >> x >> y;
      adj[x].erase(adj[x].find(y));
      adj[y].erase(adj[y].find(x));
    } else if (op=='n') {
      cin >> x;
      cout << adj[x].size() << '\n';
    } else if (op=='f') {
      cin >> x;
      set<int> res;
      for (int u : adj[x]) {
        for (int v : adj[u]) {
          res.insert(v);
        }
      }
      int cnt=0;
      for (int u : res) {
        if (adj[x].find(u) == adj[x].end() && u != x) 
          cnt++;
      }
      cout << cnt << '\n';
    } else if (op=='s') {
      fill(dis, dis+51, -1);
      cin >> x >> y;
      queue<int> q;
      q.push(x);
      dis[x] = 0;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u==y) break;
        for (int v : adj[u]) {
          if (dis[v] != -1) continue;
          q.push(v);
          dis[v] = dis[u]+1;
        }
      }
      if (dis[y]==-1) cout << "Not connected\n";
      else cout << dis[y] << '\n';
    } else {
      return 0;
    }
  }
}