#include <bits/stdc++.h>
using namespace std;
int ar[301];
int main() {
  string s;cin>>s;
  int n =s.length();
  for (int i=0;i<n;i++) {
    ar[i] = (s[i]=='+' ? 1:-1);
  }
  int ans=1e9;
  for (int i=0;i<=300;i++) {
    int cur=i, res=i;
    for (int j=0;j<n;j++) {
      cur += ar[j];
      if (cur<0) 
        break;
      res = max(res, cur);
    }
    if (cur<0) continue;
    ans = min(ans, res);
  }
  cout << ans << '\n';
}