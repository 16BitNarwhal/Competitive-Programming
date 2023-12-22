#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int n, k, a[MM];
vector<int> vals[MM];
int main() {
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<n;i++) {
    int x=a[i];
    int cur=0;
    while (x>0) {
      vals[x].push_back(cur);
      x/=2; cur++;
    }
  }
  int ans=1e9;
  for (int i=0;i<MM;i++) {
    if (vals[i].size()>=k) {
      sort(vals[i].begin(), vals[i].end());
      int cur=0;
      for (int j=0;j<k;j++) cur += vals[i][j];
      ans = min(ans, cur);
    }
  }
  cout << ans << '\n';
}