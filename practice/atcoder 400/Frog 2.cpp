// https://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int n, k, ar[MM], dp[MM];
int main() {
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> ar[i];
  for (int i=0;i<n;i++) {
    if (i==0) dp[i]=0;
    else {
      dp[i] = dp[i-1] + abs(ar[i] - ar[i-1]);
      for (int j=i-1;j>=max(0, i-k);j--) {
        dp[i] = min(dp[i], dp[j] + abs(ar[i] - ar[j]));
      }
    }
  }
  cout << dp[n-1] << '\n';
}