#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
int n, leaf[MM];
ll sum[MM], ar[MM], ans=0;
vector<int> child[MM];
void dfs(int u) {
  if (child[u].size() == 0) {
    leaf[u] = 1;
    sum[u] = ar[u];
    ans = max(ans, sum[u]);
    return;
  }
  sum[u] = ar[u];
  for (int v : child[u]) {
    dfs(v);
    leaf[u] += leaf[v];
    sum[u] += sum[v];
  }
  ans = max(ans, (sum[u] + leaf[u] - 1) / leaf[u]);
}
int main() {
  cin >> n;
  for (int i=2;i<=n;i++) {
    int u;cin>>u;
    child[u].push_back(i);
  }
  for (int i=1;i<=n;i++) 
    cin >> ar[i];
  dfs(1);
  cout << ans << '\n';
}