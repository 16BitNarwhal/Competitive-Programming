#include <bits/stdc++.h>
using namespace std;
int N, K, T[4004], D[4004], dp[4004][4004], ans=0;
int solve(int i, int skips) {
  if (dp[i][skips] != -1) return dp[i][skips];
  if (i==0) {
    return dp[0][0] = 1;
  }
  
  int a = solve(i-1, skips);
  ans = max(ans, T[i] - a);
  a = max(a + D[i], T[i] + D[i]);
  
  int b = a;
  if (skips > 0)
    b = solve(i-1, skips-1);
  ans = max(ans, T[i] - b);
  return dp[i][skips] = min(a, b);
}
int main() {
  cin >> N >> K;
  for (int i=1;i<=N;i++) 
    cin >> T[i] >> D[i];
  memset(dp, -1, sizeof(dp));
  ans = max(ans, 86400 - solve(N, K) + 1);
  cout << ans << '\n';
}