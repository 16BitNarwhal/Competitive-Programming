#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 4e4+4, MOD = 1e9+7;
ll dp[MM];
bool is_palindrome(int x) {
  int n = 0;
  int y = x;
  while (x) {
    n = n*10 + x%10;
    x /= 10;
  }
  return n == y;
}
vector<int> palindromes;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i=1;i<MM;i++) {
    if (is_palindrome(i)) 
      palindromes.push_back(i);
  }
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  for (int add : palindromes) {
    for (int i=0;i+add<MM;i++) {
      dp[i+add] = (dp[i+add] + dp[i]) % MOD;
    }
  }
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    cout << dp[n] << '\n';
  }
}