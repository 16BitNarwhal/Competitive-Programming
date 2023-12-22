#include <bits/stdc++.h>
using namespace std;
int ar[5005], dp[5005][5005];
int solve(int l, int r) {
  if (dp[l][r]!=-1) return dp[l][r];
  if (l==r) return dp[l][r]=0;
  if (ar[l]==ar[r]) return dp[l][r] = solve(l+1, r-1) + 1;
  return dp[l][r] = min(solve(l+1, r) + 1, solve(l, r-1) + 1);
}
int main() {
  int n;cin>>n;
  for (int i=0;i<n;i++) {
    cin >> ar[i];
  }
  vector<int> cmp;
  for (int i=0;i<n;i++) {
    if (i==0 || ar[i]!=ar[i-1]) {
      cmp.push_back(ar[i]);
    }
  }
  n=cmp.size();
  for (int i=0;i<n;i++) ar[i]=cmp[i];
  memset(dp, -1, sizeof dp);
  cout << solve(0, n-1) << '\n';
}