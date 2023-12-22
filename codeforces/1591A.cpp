#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    int ans=1;
    bool prev=0;
    for (int i=0;i<n;i++) {
      bool op;cin>>op;
      if (ans==-1) continue;
      if (i==0) {
        if (op) {
          ans++;
          prev=1;
        } else {
          prev=0;
        }
      } else {
        if (!op && !prev) {
          ans = -1;
        }
        if (op && prev) {
          ans += 5;
        } else if (op) {
          ans += 1;
        }
        if (op) prev=1;
        else prev=0;
      }
    }
    cout << ans << '\n';
  }
}