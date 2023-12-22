#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 101 * 1001;
ll w[101], v[101], dp[MM];
int main() {
  int n, cap;
  cin >> n >> cap;
  int sum=0;
  for (int i=1;i<=n;i++) {
    cin >> w[i] >> v[i];
    sum += v[i];
  }
  fill(dp, dp+sum+1, 2e9);
  dp[0]=0;
  for (int i=1;i<=n;i++) {
    for (int j=sum;j>=v[i];j--)
      dp[j] = min(dp[j], dp[j-v[i]] + w[i]);
  }
  for (int i=sum;i>=0;i--) {
    if (dp[i] <= cap) {
      cout << i << '\n';
      return 0;
    }
  } 
  cout << "0\n";
}