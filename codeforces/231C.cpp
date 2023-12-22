#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
int n, k, ar[MM];
ll pre[MM];
int calc(ll x) {
  for (int i=x;i<=n;i++) {
    if (x*ar[i] - (pre[i]-pre[i-x]) <= k) return i;
  }
  return 0;
}
int main() {
  cin >> n >> k;
  for (int i=1;i<=n;i++) cin >> ar[i];
  sort(ar+1, ar+n+1);
  for (int i=1;i<=n;i++) pre[i] = pre[i-1] + ar[i];
  int l=1,r=n,ans=0,idx=0;
  while (l<=r) {
    int m = l + (r-l)/2;
    int res = calc(m);
    if (res>0) {
      ans = m;
      idx = res;
      l = m+1;
    } else {
      r = m-1;
    }
  }
  cout << ans << ' ' << ar[idx] << '\n';
}