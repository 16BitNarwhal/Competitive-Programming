#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    ll n;cin>>n;
    string s;cin>>s;
    int lenX=0, lenY=0;
    for (int i=0;i<s.length();i++) {
      lenX += (s[i]=='R');
      lenY += (s[i]=='D');
    }
    if (lenX==0 || lenY==0) {
      cout << n << '\n';
      continue;
    }
    ll ans = n*n;
    ll cnt=0;
    bool first=true;
    for (int i=0;i<s.length()-1;i++) {
      cnt++;
      if (s[i]!=s[i+1]) {
        if (s[i]=='R') {
          lenX-=cnt;
          if (first) ans -= (n-1)*cnt;
          else ans -= (lenY * cnt); 
        } else {
          lenY-=cnt;
          if (first) ans -= (n-1)*cnt;
          else ans -= (lenX * cnt); 
        }

        if (first) first=false;
        cnt=0;
      }
    }
    cout << ans << '\n';
  }
}