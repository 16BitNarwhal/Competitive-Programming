#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int ar[MM];
void solve() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  for (int i=0;i<m;i++) cin>>ar[i];
  int dst;
  if (a < b) dst = a-1;
  else dst = n - a;
  sort(ar, ar+m, greater<int>());
  int cnt=0, x = abs(a-b) - 1;
  for (int i=0;i<m;i++) {
    if (cnt == x) break;
    while (ar[i] > dst + x - cnt) i++;
    if (i >= m) break;
    cnt++;
  }
  cout << cnt << '\n';
}
int main() {
  int t;cin>>t;
  while(t--) solve();
}