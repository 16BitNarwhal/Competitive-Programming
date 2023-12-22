#include <bits/stdc++.h>
using namespace std; 
const int MM = 2e5+2;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    string s;cin>>s;
    int k;cin>>k;
    map<char, bool> mp;
    for (int i=0;i<k;i++) {
      char c; cin >> c;
      mp[c] = true;
    }
    int cnt=0;
    for (int i=0;i<n;i++) {
      if (mp[s[i]]) cnt++;
    } 
    bool flag=false, seen=false;
    if (cnt>=2) flag=true;
    int ans=0;
    for (int i=0;i<n;) {
      while (mp[s[i]]) seen=true, i++;
      cnt = 0;
      while (i<n && !mp[s[i]]) {
        i++; cnt++; 
        if (i==n) cnt=0;
      }
      if (seen && flag) ans = max(ans, cnt+1);
      ans = max(ans, cnt);
    }
    cout << ans << '\n';
  }
}