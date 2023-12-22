#include <bits/stdc++.h>
using namespace std;
const int MM = 2002;
int ar[MM], dp[MM][MM];
int main() {
  int t;cin>>t;
  while (t--) {
    int n, k;
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin >> ar[i];
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=n;j++) dp[i][j]=0;
    }
    for (int i=1;i<=n;i++) { 
      for (int j=1;j<=i;j++) { 
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + (ar[i]==j)); 
      }
    }
    int ans=-1;
    for (int i=n;i>=0;i--) {
      if (dp[n][i]>=k) {
        ans = n-i;
        break;
      }
    }
    cout << ans << '\n';
  }
}