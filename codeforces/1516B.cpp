#include <bits/stdc++.h>
using namespace std;
const int MM = 2005;
int pre[MM];
void solve() {
  int n;cin>>n;
  for (int i=1;i<=n;i++) {
    int x;cin>>x;
    pre[i] = pre[i-1] ^ x;
  } 
  bool ans=0;
  for (int i=1;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      if ((pre[n] ^ pre[j]) == (pre[j] ^ pre[i]) &&
          (pre[j] ^ pre[i]) == pre[i])
          ans = 1;
    }
    if ((pre[n] ^ pre[i]) == pre[i]) ans=1;
  }
  cout << (ans ? "YES\n" : "NO\n");
}
int main() {
  int t;cin>>t;
  while(t--) solve();
}