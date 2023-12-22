#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5+2;
int dpl[MM], dpr[MM];
void solve() {
  int n;cin>>n;
  string s;cin>>s;
  for (int i=0;i<=n;i++) {
    if (i==0 || s[i-1]=='R') {
      dpl[i] = i;
    } else if (i==1 || s[i-2]=='L') {
      dpl[i] = i-1;
    } else {
      dpl[i] = dpl[i-2];
    }
  }
  for (int i=n;i>=0;i--) {
    if (i==n || s[i]=='L') {
      dpr[i] = i;
    } else if (i==n-1 || s[i+1]=='R') {
      dpr[i] = i+1;
    } else {
      dpr[i] = dpr[i+2];
    }
  }
  for (int i=0;i<=n;i++) 
    cout << dpr[i] - dpl[i] + 1 << ' ';
  cout << '\n';
}
int main() {
  int t;cin>>t;
  while(t--) solve();
}