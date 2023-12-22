#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2, mod = 1e9+7;
int add(int a, int b) { return (a+b<0?mod:0) + (a+b>=mod?-mod:0) + (a+b); }
int mult(int a, int b) { return 1LL * a * b % mod; }
int dp[MM][3], cnt[3];
int main() {
  int n, l, r;
  cin >> n >> l >> r;
  l--;
  cnt[0] = r/3 - l/3;
  cnt[1] = (r+2)/3 - (l+2)/3;
  cnt[2] = (r+1)/3 - (l+1)/3;
  dp[0][0] = 1;
  for (int i=0;i<n;i++) {
    for (int j=0;j<3;j++) { 
      for (int k=0;k<3;k++)
        dp[i+1][(j+k)%3] = add(dp[i+1][(j+k)%3], mult(dp[i][j], cnt[k]));
    }
  }
  cout << dp[n][0] << '\n';
}