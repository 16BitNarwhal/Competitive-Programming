#include <bits/stdc++.h>
using namespace std; 
int main() { 
  string s;cin>>s;
  int cnt=1;
  bool ans = false;
  for (int i=1;i<s.length();i++) {
    if (s[i] != s[i-1]) {
      cnt=1;
    } else {
      cnt++;
      if (cnt==7) {
        ans = true;
      }
    }
  }
  cout << (ans ? "YES" : "NO") << endl;
}