#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
map<char,int> mp[MM];
int main() {
  int t;cin>>t;
  while(t--) {
    int n,k;cin>>n>>k;
    string s;cin>>s;
    for (int i=0;i<k;i++) mp[i].clear();
    for (int i=0;i<(k+1)/2;i++) { 
      for (int j=0;j<=n;j+=k) {
        if (j-i-1>=0) mp[i][s[j-i-1]]++;
        if (j+i<n && i<k/2) mp[i][s[j+i]]++; 
      } 
    }
    int ans=0;
    for (int i=0;i<(k+1)/2;i++) {
      int cnt=0, mx=0;
      for (char ch='a';ch<='z';ch++) {
        mx = max(mx, mp[i][ch]);
        cnt += mp[i][ch];
      }
      ans += cnt - mx;
    }
    cout << ans << '\n';
  }
}

/*

hippopotomonstrosesquippedaliophobia
h       om       es       al       a | aaehlmos
 i     t  o     s  q     d  i     i  | diiioqst
  p   o    n   o    u   e    o   b   | benooopu
   p p      s r      i p      p o    | iopppprs
    o        t        p        h     | hopt

*/