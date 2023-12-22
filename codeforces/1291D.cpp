#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int p[MM][26];
string s;
int main() {
  cin >> s;
  int n = s.size();
  for (int i=0;i<n;i++)
    p[i][s[i]-'a']++;
  for (int i=1;i<n;i++) {
    for (int j=0;j<26;j++) p[i][j] += p[i-1][j];
  }
  int q;cin>>q;
  while(q--) {
    int l,r;cin>>l>>r;
    l--;r--;
    if (l==r || s[l] != s[r]) {
      cout << "Yes\n"; 
      continue;
    }
    int cnt=0;
    for (int i=0;i<26;i++) {
      if (p[r][i] - (l>0?p[l-1][i]:0) > 0) cnt++;
    }
    if (cnt>=3) cout << "Yes\n";
    else cout << "No\n";
  }
}