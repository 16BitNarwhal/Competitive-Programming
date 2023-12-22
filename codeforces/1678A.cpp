#include <bits/stdc++.h>
using namespace std;


int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    map<int,int> cnt;
    for (int i=0;i<n;i++) {
      int x;cin>>x;
      cnt[x]++;
    }
    if (cnt[0]==0) {
      int ans = n+1;
      for (auto p:cnt) {
        if (p.second >= 2) {
          ans = n; break;
        }
      }
      cout << ans << '\n';
    } else {
      cout << n-cnt[0] << '\n';
    }
  }
}