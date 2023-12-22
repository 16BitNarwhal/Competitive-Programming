#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
pair<int,int> ar[1010];
int dp[MM];
int main() {
  int n, W;
  cin >> n >> W;
  int sv=0, sw=0;
  for (int i=0;i<n;i++) {
    cin >> ar[i].first >> ar[i].second;
    sv += ar[i].first;
    sw += ar[i].second;
  }
  if (sw <= W) {
    cout << sv << '\n';
    return 0;
  }
  W = sw - W;
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i=0;i<n;i++) {
    int v = ar[i].first;
    int w = ar[i].second;
    for (int j=W+1050;j>=w;j--) {
      dp[j] = min(dp[j], dp[j-w]+v);
    }
  }
  int res=1e9;
  for (int i=W;i<=W+1050;i++)
    res = min(res, dp[i]);
  cout << sv - res << '\n';
}