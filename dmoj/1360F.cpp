#include <bits/stdc++.h>
using namespace std;
int diff(string a, string b) {
  int cnt=0;
  for (int i=0;i<a.length();i++) {
    if (a[i]!=b[i]) cnt++;
  }
  return cnt;
}
int main() { 
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    int n, m; cin >>n >> m;
    vector<string> a(n);
    for (auto &i:a) cin>>i;
    for (int i=0;i<m;i++) {
      string s = a[0];
      for (char c='a';c<='z';c++) {
        s[i] = c;
        bool flag = 1;
        for (int j=0;j<n;j++) {
          if (diff(s, a[j]) > 1) flag = 0;
        }
        if (flag) {
          cout << s << '\n';
          goto q;
        }
      }
    }
    cout << "-1\n";
    q:;
  }
}