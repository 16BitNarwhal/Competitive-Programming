#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    string s;cin>>s; 
    int ans=-1;
    for (int i=0;i<n;i++) {
      if (i>0 && s[i]=='a' && s[i-1]=='a') {
        // aa
        ans=2;
        break;
      } else if (i>1 && s[i]=='a' && s[i-2]=='a') {
        // aba
        if (ans==-1 || ans>3) ans=3;
      } else if (i>2 && s[i]=='a' && s[i-3]=='a' && s[i-1]!=s[i-2]) {
        // abca
        if (ans==-1 || ans>4) ans=4;
      } else if (i>5 && s[i]=='a' && s[i-3]=='a' && s[i-6]=='a'
         && s[i-5]==s[i-4] && s[i-2]==s[i-1] && s[i-1]!=s[i-5]) {
        // abbacca
        if (ans==-1 || ans>7) ans=7;
      }
    }
    cout << ans << '\n';
  }
}