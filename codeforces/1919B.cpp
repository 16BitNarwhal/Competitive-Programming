#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    string s;cin>>s;
    int ans=0;
    for (int i=0;i<n;i++) {
      int x = (s[i]=='+'?1:-1);
      ans += x;
    }
    cout << abs(ans) << '\n';
  }
}