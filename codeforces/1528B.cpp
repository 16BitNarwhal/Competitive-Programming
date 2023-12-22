#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+1, mod = 998244353;
int n, dp[MM]; 
int main() {
  cin >> n;
  for (int i=1;i<=n;i++) {
    for (int j=i+i;j<=n;j+=i)
      dp[j]++; // num divisors 
  }
  int sum=1;
  dp[0] = 1;
  for (int i=1;i<=n;i++) {
    dp[i] = (dp[i] + sum) % mod;
    sum = (sum + dp[i]) % mod;
  }
  cout << dp[n] << '\n';
}