#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;cin>>s;
  int cnt=0;
  bool use=0;
  for (int i=0;i<s.length();i++) {
    if (s[i]=='(') {
      cnt++;
    } else {
      cnt--;
      if (cnt<0) {
        if (!use) {
          use=1;
          cnt+=2;
        } else {
          cout << "NO\n";
          return 0;
        }
      }
    }
  }
  if (cnt==0 || (cnt==2 && !use)) cout << "YES\n";
  else cout << "NO\n";
}