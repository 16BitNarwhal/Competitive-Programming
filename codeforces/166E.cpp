#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, dp[4], tmp[4];
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  dp[0] = 1;
  for (int i=0;i<n;i++) {
    for (int j=0;j<4;j++) tmp[j] = dp[j];
    for (int j=0;j<4;j++) {
      dp[j] = 0;
      for (int k=0;k<4;k++) {
        if (j==k) continue;
        add(dp[j], tmp[k]);
      }
    }
  }
  cout << dp[0] << '\n';
}