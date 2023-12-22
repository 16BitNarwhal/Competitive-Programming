#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
vector<int> a[11];
map<vector<int>, bool> ban;
int main() {
  int n; cin >> n;
  for (int i=1;i<=n;i++) {
    int m; cin >> m;
    a[i] = vector<int>(m+1);
    for (int j=1;j<=m;j++)
      cin >> a[i][j];
  }
  int m; cin >> m;
  for (int i=1;i<=m;i++) {
    vector<int> v = vector<int>(n+1);
    for (int j=1;j<=n;j++)
      cin >> v[j];
    ban[v] = true;
  }
  vector<int> v = vector<int>(n+1);
  for (int i=1;i<=n;i++) 
    v[i] = a[i].size()-1;
  if (ban.count(v)==0) {
    for (int i=1;i<=n;i++)
      cout << v[i] << ' ';
    cout << '\n';
    return 0;
  }
  vector<int> ans;
  int best=0;
  for (auto [vec, _] : ban) {
    vector<int> v = vector<int>(vec);
    int sum=0;
    for (int i=1;i<=n;i++)
      sum += a[i][v[i]];
    for (int i=1;i<=n;i++) {
      if (v[i]==1) continue;
      sum -= a[i][v[i]];
      v[i]--;
      sum += a[i][v[i]];
      if (ban.count(v)==0) {
        if (sum > best) {
          best = sum;
          ans = v;
        }
      }
      sum -= a[i][v[i]];
      v[i]++;
      sum += a[i][v[i]];
    }
  }
  for (int i=1;i<=n;i++) 
    cout << ans[i] << ' ';
  cout << '\n';
}