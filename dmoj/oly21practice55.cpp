#include <bits/stdc++.h>
using namespace std;
unordered_map<string, bool> mp;
string ans="";
void check(string s, int i) { 
  if (ans!="") return;
  if (!mp[s]) {
    ans = s; return;
  }
  if (i==s.length()) return;
  for (int c='a';c<='z';c++) {
    s[i] = c;
    check(s, i+1);
  }
}
int main() {
  string s;cin>>s;
  int n=s.length();
  for (int i=0;i<n;i++) {
    string cur = "";
    for (int j=i;j<n;j++) {
      cur += s[j];
      mp[cur] = 1;
    }
  }
  for (int i=1;i<n;i++) {
    if (ans!="") break;
    string cur="";
    for (int j=0;j<i;j++) cur+='a';
    check(cur, 0); 
  }
  cout << ans << '\n';
}