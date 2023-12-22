#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5+3;
// d[x] = max dist between 2 x's or [1,first x] or [last x,n]
int n, d[MM], prv[MM], ans[MM];
void solve() {
  cin >> n;
  memset(d, 0, sizeof d);
  memset(prv, 0, sizeof prv);
  memset(ans, -1, sizeof ans);
  for (int i=1;i<=n;i++) {
    int x;cin>>x;
    d[x] = max(d[x], i-prv[x]);
    prv[x] = i;
  }
  for (int x=1;x<=n;x++) 
    d[x] = max(d[x], n+1-prv[x]);
  for (int x=1;x<=n;x++) {
    for (int i=d[x];i<=n;i++) {
      if (ans[i]>0) break;
      ans[i] = x;
    }
  }
  for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
  cout << '\n';
}
int main() {
  int t;cin>>t;
  while(t--) solve();
}