#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int n, vals[MM];
string ar[MM];
int cnt_sub(string s, char a) {
  int x=0, y=0;
  for (char c:s) {
    if (c==a) x++;
    else y++;
  }
  return x-y;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    cin>>n;
    for (int i=0;i<n;i++)
      cin >> ar[i];
    int ans=0;
    for (char a='a';a<='e';a++) {
      for (int i=0;i<n;i++) 
        vals[i] = cnt_sub(ar[i], a);
      sort(vals, vals+n);
      reverse(vals, vals+n);
      int x=0, res=0;
      for (int i=0;i<n;i++) {
        if (x + vals[i] > 0) {
          x += vals[i];
          res++;
        } else break;
      }
      ans = max(ans, res);
    }
    cout << ans << '\n';
  }

}

/*
for a in abcde
  dp[i+cnt(a)][j+cnt(!a)] = max(dp[i+cnt(a)][j+cnt(!a)], dp[i][j]+1)
  ans = max(ans, loop dp[cnt a][j -> cnt a] )

////////////

for a in abcde
  sort strings by cnt(a) - cnt(!a)
  then pick

*/