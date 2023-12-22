#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;cin>>s;
  bool valid=true;
  for (int i=0;i<s.size();i++) {
    if (s[i]=='0') s[i]+=10;
    if (i && s[i-1]!=s[i]-1 && s[i-1]!=s[i]+1) {
      valid=false;
      break;
    }
  }
  cout << (valid ? "VALID\n" : "INVALID\n");
}