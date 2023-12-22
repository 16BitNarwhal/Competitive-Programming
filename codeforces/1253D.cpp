#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int ar[MM];
int root(int u) {
  if (ar[u]==u) return u;
  return ar[u]=root(ar[u]);
}
void join(int a, int b) {
  int ra = root(a);
  int rb = root(b);
  if (ra<rb) swap(ra, rb);
  ar[ra] = rb;
}
int main() {
  int n,m; cin>>n>>m;
  for (int i=1;i<=n;i++) ar[i]=i;

  for (int i=0,u,v;i<m;i++) {
    cin >> u >> v;
    join(u, v);
  }
  int ans=0;
  int rt = n+1;
  for (int i=n;i>=1;i--) {
    if (i > rt && root(i) != rt) {
      join(i, i+1);
      ans++;
    }
    rt = root(i);
  }

  cout << ans << '\n';
  
}