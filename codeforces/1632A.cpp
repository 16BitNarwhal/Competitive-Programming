#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    string s;cin>>s;
    if (n == 1) {
      cout << "YES\n";
    } else if (n == 2) {
      cout << (s[0]==s[1] ? "NO\n" : "YES\n");
    } else if (n > 2) {
      cout << "NO\n";
    }
  }
}