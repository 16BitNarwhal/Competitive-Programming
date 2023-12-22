#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
int ar[202][2], dp[202][6000], ndp[202][6000];
void mx(int &a, int b) { if (b > a) a = b; }
int main() {
  int n, k;
  cin >> n >> k;
  for (int i=0;i<n;i++) {
    ll x; cin >> x;
    while (x%2==0) {
      ar[i][0]++;
      x/=2;
    }
    while (x%5==0) {
      ar[i][1]++;
      x/=5;
    }
  }
  for (int i=0;i<202;i++) for (int j=0;j<6000;j++) dp[i][j] = ndp[i][j] = -1;
  dp[0][0] = 0;
  for (int i=0;i<n;i++) {
    for (int j=0;j<=k;j++) for (int l=0;l<6000;l++) ndp[j][l] = dp[j][l];
    for (int j=0;j<k;j++) {
      for (int l=0;l<6000;l++) {
        if (dp[j][l]==-1) continue;
        mx(ndp[j+1][l+ar[i][1]], dp[j][l] + ar[i][0]);
      }
    }
    for (int j=0;j<=k;j++) for (int l=0;l<6000;l++) dp[j][l] = ndp[j][l];
  }
  int ans=0;
  for (int i=0;i<6000;i++) {
    mx(ans, min(i, dp[k][i]));
  }
  cout << ans << '\n';
}