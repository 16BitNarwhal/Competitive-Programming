#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    int n = s.size();
    map<char, bool> seen;
    int sz=n;
    for (int i=0;i<n;i++) {
      if (seen[s[i]]>0) {
        sz = i;
        break;
      }
      seen[s[i]] = true;
    }
    bool ans=true;
    for (int i=sz;i<n;i++) {
      if (s[i] != s[i%sz]) {
        ans = false; break;
      }
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }
}