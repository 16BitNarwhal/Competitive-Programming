#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5+2;
int n, m, ar[MM];
vector<int> child[MM];
int dfs(int u) {
  if (child[u].size()==0) return 1;
  int cnt = (ar[u]==0?0:1e9);
  for (int v : child[u]) {
    if (ar[u]) {
      cnt = min(cnt, dfs(v));
    } else {
      cnt += dfs(v);
    }
  }
  return cnt;
}
int main() {
  cin >> n;
  for (int i=1;i<=n;i++) cin >> ar[i];
  for (int i=2;i<=n;i++) {
    int x;cin>>x;
    child[x].push_back(i);
  }
  m=0;
  for (int i=1;i<=n;i++) {
    if (child[i].size()==0) m++;
  } 
  cout << m-dfs(1)+1 << '\n';
}