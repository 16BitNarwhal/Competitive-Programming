#include <bits/stdc++.h>
using namespace std;
const int MM = 5005;

int n, ar[MM], tbl[MM][MM]; // l, r
int ans[MM]; // len
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i=1;i<=n;i++) {
    cin >> ar[i];
  }
  memset(ans, 0x3f, sizeof ans);
  for (int len=1;len<=n;len++) {
    for (int i=1;i<=n;i++) {
      int l = i, r = i+len-1;
      if (r > n) break;
      tbl[l][r] = abs(ar[r]-ar[l]) + tbl[l+1][r-1];
      ans[len] = min(ans[len], tbl[l][r]);
    }
  }
  for (int i=1;i<=n;i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}