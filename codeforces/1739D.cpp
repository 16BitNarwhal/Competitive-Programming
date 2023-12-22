#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int pa[MM], cnt;
vector<int> children[MM];
int dfs(int u, int m) {
  int dis = 0;
  for (int v : children[u]) {
    dis = max(dis, dfs(v, m)+1);
  }
  // move parent edge
  if (pa[u] != 1 && dis >= m-1) { 
    cnt++;
    dis = -1;
  }
  return dis;
}
int main() {
  int t;cin>>t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    for (int i=1;i<=n;i++)
      children[i].clear();
    pa[1]=1;

    for (int i=2;i<=n;i++) {
      cin >> pa[i];
      children[pa[i]].push_back(i);
    }

    int l=1, r=n-1, ans=n-1;
    while (l <= r) {
      int m = (l+r)/2;

      cnt=0;
      dfs(1, m);

      if (cnt <= k) {
        ans = m;
        r = m-1;
      } else {
        l = m+1;
      }
    }
    cout << ans << '\n';
  }
}

/*

Goal: minimize all depths of tree from root

Operation (k times):
- set the parent of a node/subtree to the root

Observations:
- order of ops doesn't matter

Approach:
- binary search on answer (height), check if possible to use k operations to all depths <= mid
- check is as follows:
  - use dfs postorder to get distance to leaf
    - if dist + 1 == mid, use operation (cnt++) and set dist = -1 so that parent's dist = max(0, other children)
    - note: operation moves edgee between parent and current node
  - if num ops used > k, return false

*/