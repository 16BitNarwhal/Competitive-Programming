#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    string s;cin>>s;
    int cnt[26];
    fill(cnt, cnt+26, 0);
    for (int i=0;i<s.length();i++) cnt[(int)(s[i]-'a')]++;
    int ans=0, one=0;
    for (int i=0;i<26;i++) 
      if (cnt[i]>=2) { 
        ans++;
      } else if (cnt[i]==1) {
        one++;
      }
    ans += one/2;
    cout << ans << "\n";
  }

}