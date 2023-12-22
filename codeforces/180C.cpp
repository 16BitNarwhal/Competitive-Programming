#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n, ar[MM], pfx[MM];
int main() {
  string s;cin>>s;
  n = s.size();
  for (int i=0;i<n;i++) { 
    if (s[i] < 'a') ar[i] = 1;
    else ar[i] = 0;
    pfx[i+1] = pfx[i] + ar[i];
  }
  int ans=1e9;
  for (int i=0;i<=n;i++) {
    ans = min(ans, (i - pfx[i]) + (pfx[n]-pfx[i]));
  }
  cout << ans << '\n';
}