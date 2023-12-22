#include <bits/stdc++.h>
using namespace std;
typedef pair<double, int> pi;
int n, m, dp[5005];
pi ar[5005];
int main() {
  cin >> n >> m;
  for (int i=0;i<n;i++)
    cin >> ar[i].second >> ar[i].first;
  sort(ar, ar+n);
  int mx = 1;
  fill(dp, dp+n+1, 1); 
  for (int i=0;i<n;i++) { 
    for (int j=0;j<i;j++) {
      if (ar[i].second >= ar[j].second) {
        dp[i] = max(dp[i], dp[j]+1);
        mx = max(mx, dp[i]);
      }
    }
  } 
  cout << n-mx << '\n';
}