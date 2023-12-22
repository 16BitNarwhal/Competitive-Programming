// https://atcoder.jp/contests/dp/tasks/dp_a
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int ar[MM], dp[MM];
int main() {
  int n;cin>>n;
  for (int i=0;i<n;i++)cin>>ar[i];
  for (int i=0;i<n;i++) {
    if (i==0) dp[i]=0;
    else if (i==1) dp[i] = abs(ar[i]-ar[i-1]);
    else dp[i] = min(dp[i-1] + abs(ar[i]-ar[i-1]), dp[i-2] + abs(ar[i]-ar[i-2]));
  }
  cout << dp[n-1] << '\n';
}