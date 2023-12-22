#include <bits/stdc++.h>
using namespace std;
const int MM = 2002;
int n, cnt[27][MM];
int get(int a, int l, int r) {
  return cnt[a][r] - cnt[a][l-1];
}
void solve() { 
  memset(cnt, 0, sizeof cnt);
  cin >> n;
  for (int i=1, a;i<=n;i++) {
    cin>>a;
    cnt[a][i]++;
  }
  for (int i=1;i<=26;i++) 
    for (int j=1;j<=n;j++) 
      cnt[i][j] += cnt[i][j-1];
  int ans=0;
  for (int i=1;i<=26;i++) ans = max(ans, cnt[i][n]);
  for (int l=2;l<n;l++) {
    for (int r=l;r<n;r++) {
      for (int a=1;a<=26;a++) {
        for (int b=1;b<=26;b++) {
          int y = get(a,l,r);
          int x = get(b, 1, l-1);
          if (x == get(b, r+1, n))
            ans = max(ans, x+y+x);
        }
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) solve();
}