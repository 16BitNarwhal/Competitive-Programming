#include <bits/stdc++.h>
using namespace std;
const int MM = 101*101;
int a[101], b[101], dp[101][MM];
int main() {
  int n;
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<n;i++) cin >> b[i];
  priority_queue<int> q;
  for (int i=0;i<n;i++) q.push(b[i]);
  int sum=0;
  for (int i=0;i<n;i++) sum += a[i];
  int K=0, tmp=0;
  while (tmp < sum) {
    tmp += q.top(); q.pop();
    K++;
  }
  for (int i=0;i<=K;i++) fill(dp[i], dp[i]+MM, -1);
  dp[0][0] = 0;
  for (int i=0;i<n;i++) {
    for (int k=K;k>=0;k--) {
      for (int j=0;j<MM-b[i];j++) {
        if (dp[k][j]==-1) continue;
        dp[k+1][j+b[i]] = max(dp[k+1][j+b[i]], dp[k][j]+a[i]);
      }
    }
  }
  int res=0;
  for (int i=sum;i<MM;i++) res = max(res, dp[K][i]);
  cout << K << ' ' << sum - res << '\n';
}