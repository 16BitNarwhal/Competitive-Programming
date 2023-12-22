#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int MM = 2e5+2;
bool col[MM];
vector<int> adj[MM];
int cnt[MM], ans[MM];
int dfs(int u, int pa) {
  int cnt = col[u];
  for (int v : adj[u]) {
    if (v==pa) continue;
    col[v] = !col[u];
    cnt += dfs(v, u);
  }
  return cnt;
}
int main() {
  int t;cin>>t;
  while (t-- ){
    int n;cin>>n;
    for (int i=0;i<=n;i++) {
      adj[i].clear();
      col[i] = 0;
      cnt[i] = 0;
      ans[i] = 0;
    }
    for (int i=1;i<n;i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int a = dfs(1, -1);
    int b = n-a;
    if (a>b) {
      swap(a,b);
      for (int i=1;i<=n;i++) col[i] = !col[i];
    }
    for (int i=0;(1<<i)<=n;i++) {
      if (a&(1<<i)) {
        for (int j=1;j<=n;j++) {
          if (col[j] && ans[j]==0) {
            ans[j] = (1<<i) + cnt[i]; 
            cnt[i]++;
            if (cnt[i]==(1<<i)) break;
          }
        }
      } else {
        for (int j=1;j<=n;j++) {
          if (!col[j] && ans[j]==0) {
            ans[j] = (1<<i) + cnt[i]; 
            cnt[i]++;
            if (cnt[i]==(1<<i)) break;
          }
        }
      }
    }
    for (int i=1;i<=n;i++) cout << ans[i] << ' ';
    cout << '\n';
  }
}