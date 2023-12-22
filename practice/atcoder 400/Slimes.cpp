#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll pfx[404], dp[404][404];
// ll calc(int l, int r) {
//   if (l>=r) return 0;
//   if (mem[l][r]) return mem[l][r];
//   ll mn=1e18;
//   for (int i=l+1;i<=r;i++) {
//     mn = min(mn, calc(l, i-1) + calc(i, r));
//   }
//   return mem[l][r] = mn + pfx[r] - pfx[l-1];
// }
int main() {
  cin >> n;
  for (int i=1;i<=n;i++) {
    cin >> pfx[i];
    pfx[i] += pfx[i-1];
  }
  for (int len=2;len<=n;len++) {
    for (int l=1;l+len-1<=n;l++) {
      int r = l+len-1;
      ll mn = 1e18;
      for (int k=l+1;k<=r;k++) {
        mn = min(mn, dp[l][k-1] + dp[k][r]);
      }
      dp[l][r] = mn + pfx[r] - pfx[l-1]; 
    } 
  }
  cout << dp[1][n] << '\n';
}