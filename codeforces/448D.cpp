#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k;
bool check(ll x) {
  ll cnt=0;
  for (ll i=1;i<=n;i++) {
    ll cur = min(x/i, m);
    cnt += cur;
  }
  return cnt>=k;
}
int main() {
  cin >> n >> m >> k;
  ll l=1, r=n*m, ans=-1;
  while (l<=r) {
    ll m = l + (r-l)/2;
    if (check(m)) {
      ans = m;
      r = m-1;
    } else {
      l = m+1;
    }
  }
  cout << ans << '\n';
}
