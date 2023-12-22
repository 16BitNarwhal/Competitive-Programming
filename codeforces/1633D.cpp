#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e3+5;
ll dp[110000], cst[MM], gain[MM], val[MM];
void init() {
  memset(val, 0x3f, sizeof(val));
  val[0] = val[1] = 0;
  for (int i=1;i<MM;i++) {
    set<int> s;
    for (int j=1;j*j<=i;j++) {
      s.insert(j);
      s.insert(i/j);
    }
    for (int x : s)
      val[i + x] = min(val[i + x], val[i] + 1);
  }
}
int main() {
  init();
  int t;cin>>t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    ll sum=0;
    for (int i=1;i<=n;i++) {
      int x;cin>>x;
      cst[i] = val[x];
      sum += cst[i];
    }
    k = min(k, sum);
    for (int i=1;i<=n;i++) cin >> gain[i];
    for (int i=0;i<=k;i++) dp[i] = 0;
    for (int i=1;i<=n;i++) {
      for (int j=k;j>=cst[i];j--) {
        dp[j] = max(dp[j], dp[j-cst[i]] + gain[i]);
      }
    }
    ll ans=0;
    for (int i=0;i<=k;i++) ans = max(ans, dp[i]);
    cout << ans << '\n';
  }
}

