#include <bits/stdc++.h>
using namespace std;
const int MM = 2222;
int inp[MM][MM], g[MM][MM];
void add(int i1, int j1, int i2, int j2) {
  g[i1][j1]++;
  g[i2+1][j1]--;
  g[i1][j2+1]--;
  g[i2+1][j2+1]++;
}
int main() {
  int n,k;
  cin>>n>>k;
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
      char c;cin>>c;
      inp[i][j] = (c=='B');
    }
  }
  int cnt=0;
  for (int i=1;i<=n;i++) {
    vector<int> v;
    for (int j=1;j<=n;j++) {
      if (inp[i][j])
        v.push_back(j);
    }
    if (v.empty()) cnt++;
    else if (v.back() - v[0] < k) {
      add(max(i-k+1,1),max(v.back()-k+1,1),i,v[0]);
    }
  }
  for (int j=1;j<=n;j++) {
    vector<int> v;
    for (int i=1;i<=n;i++) {
      if (inp[i][j])
        v.push_back(i);
    }
    if (v.empty()) cnt++;
    else if (v.back() - v[0] < k) { 
      add(max(v.back()-k+1,1),max(j-k+1,1),v[0],j);
    }
  }
  int ans=0;
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
      g[i][j] += g[i-1][j];
      g[i][j] += g[i][j-1];
      g[i][j] -= g[i-1][j-1];
      ans = max(ans, g[i][j] + cnt);
    }
  }
  cout << ans << '\n'; 
}