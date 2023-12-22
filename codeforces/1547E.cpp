#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5+2, INF=2e9;
int a[MM], pos[MM], pre[MM], suf[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) { 
    memset(pos, 0, sizeof pos);
    int n,k;cin>>n>>k;
    fill(a, a+n+2, INF);
    fill(pre, pre+n+2, INF);
    fill(suf, suf+n+2, INF);
    for (int i=0;i<k;i++) cin >> pos[i];
    for (int i=0;i<k;i++) {
      int x;cin>>x;
      a[pos[i]] = x;
    }
    for (int i=1;i<=n;i++) 
      pre[i] = min(pre[i-1]+1, a[i]);
    for (int i=n;i>=0;i--) 
      suf[i] = min(suf[i+1]+1, a[i]);
    for (int i=1;i<=n;i++) 
      cout<<min(pre[i], suf[i]) << ' ';
    cout << '\n';
  }
}