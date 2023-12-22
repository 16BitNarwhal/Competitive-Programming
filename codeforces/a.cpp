#include <bits/stdc++.h>
using namespace std;
const int MM = 2e6;
int dp[MM];
int main() {
  int n;cin>>n;
  dp[0] = 1;
  for (int i=0;i<=n;i++) 
    dp[i+4] += dp[i];
  for (int i=0;i<=n;i++)
    dp[i+5] += dp[i];
  cout << dp[n] << '\n';
}