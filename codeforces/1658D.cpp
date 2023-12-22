#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5;
int a[MM], b[MM], ok[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    int l, r;
    cin>>l>>r;
    for (int i=0;i<r-l+1;i++) {
      cin >> a[i];
      b[i] = 0;
      ok[i] = 0;
    }
    int x=0;
    for (int k=17;k>=0;k--) {
      unordered_map<int,int> has;
      for (int i=0;i<r-l+1;i++) {
        if ((i+l)&(1<<k)) ok[i] += (1<<k);
        has[ok[i]]++;
      }
      unordered_map<int,int> cnt;
      bool flip=false;
      for (int i=0;i<r-l+1;i++) {
        if (a[i]&(1<<k)) b[i] += (1<<k);
        cnt[b[i]]++;
      }
      for (auto [k,v]:has) if (cnt[k]!=v) flip=true;
      for (auto [k,v]:cnt) if (has[k]!=v) flip=true;
      if (flip) {
        for (int i=0;i<r-l+1;i++) b[i] ^= (1<<k);
        x |= (1<<k);
      }
    }
    cout << x << '\n';
  }
}