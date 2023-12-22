#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int n, ar[MM];
ll dp[MM];
int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    int x;cin>>x;
    ar[x]++;
  }
  for (int i=1;i<MM;i++) {
    dp[i] = max(dp[i-2] + 1LL*ar[i]*i, dp[i-1]);
  }
  cout << dp[MM-1] << '\n';
}