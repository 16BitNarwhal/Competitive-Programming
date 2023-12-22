#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ar[55];
ll dp[55][55];
ll calc(int l, int r) {
  if (l>=r) return 0;
  if (dp[l][r]) return dp[l][r];
  ll mn = 1e18;
  for (int i=l+1;i<=r-1;i++) {
    mn = min(mn, calc(l, i-1) + calc(i, r));
  }
}
int main() {
  
}