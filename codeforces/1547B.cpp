#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    string s;cin>>s;
    int l=-1, r=-1, n = s.length();
    for (int i=0;i<n;i++) {
      if (s[i]=='a') {
        l = r = i;
      }
    }
    char c='a';
    if (l==-1) {
      cout << "NO\n"; goto q;
    } 
    while (l>0 && r<n-1) {
      if (s[l-1]==c+1) {
        l--; c++;
      } else if (s[r+1]==c+1) {
        r++; c++;
      } else {
        cout << "NO\n"; goto q;
      }
    }
    while (l>0) { 
      if (s[l-1]==c+1) {
        l--; c++;
      } else break;
    }
    while (r<n-1) { 
      if (s[r+1]==c+1) {
        r++; c++;
      } else break;
    } 
    if (l==0 && r==n-1) cout << "YES\n";
    else cout << "NO\n";
    q:;
  }
}