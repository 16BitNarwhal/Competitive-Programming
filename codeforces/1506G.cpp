#include <bits/stdc++.h>
using namespace std;
string s;
set<char> need;
bool seenall(set<char> &seen) {
  for (char c : need) {
    if (!seen.count(c))
      return false;
  }
  return true;
}
int get(int j) {
  int n = s.size();
  set<char> seen;
  char mx='a';
  int idx=-1;
  for (int i=n-1;i>j;i--) {
    seen.insert(s[i]);
    if (need.count(s[i]) && seenall(seen)) {
      if (s[i] >= mx) {
        mx = s[i];
        idx = i;
      }
    }
  }
  return idx;
}
int main() {
  int t;cin>>t;
  while (t--) {
    cin>>s;
    need.clear();
    for (char c : s) need.insert(c);
    string res="";
    int n = need.size();
    int j = -1;
    for (int i=0;i<n;i++) {
      int id = get(j);
      need.erase(s[id]);
      res += s[id];
      j = id; 
    }
    cout << res << '\n';
  }
}