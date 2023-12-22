#include <bits/stdc++.h>
using namespace std;

int n, ar[1001][2], dp[1001][11];
int rec(int i, int cnt) {
  if (i==n) return 0;
  if (dp[i][cnt]!=-1) return dp[i][cnt];

  int res=-1e9;

  // get correct and not 10 in a row
  if (cnt<10) {
    if (cnt&1) res=max(res,rec(i, cnt+1)+ar[i][0]);
    else res=max(res,rec(i+1, cnt+1)+ar[i][1]);
  }
  
  // get wrong
  res=max(res,rec(i+1, 1)-1);
  
  return dp[i][cnt] = res;

}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t=10;
  while (t--) {
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i=0;i<n;i++) {
    for (int j=0;j<2;j++)
    cin >> ar[i][j];
  }
  cout << rec(0, 1) << '\n';
  }
}