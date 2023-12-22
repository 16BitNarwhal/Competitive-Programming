#include <bits/stdc++.h>
using namespace std;
int nxt[(int)2e5+5];
int main() {
  int t;cin>>t;
  while(t--) {
    int ans=0;
    string s;cin>>s;
    for (int i=0;i<s.length();i++) {
      if (s[i]=='0') nxt[i] = (i==0?-1:nxt[i-1]);
      else nxt[i] = i;
    }
    for (int r=0;r<s.length();r++) {
      int x=0;
      for (int l=r;l>=max(0, r-18); l--) {
        if (s[l]=='0') continue;
        x += 1<<(r-l);
        if (x <= r - (l==0? -1:nxt[l-1]))
          ans ++;
      }
    }
    cout << ans << '\n';
  }
} 