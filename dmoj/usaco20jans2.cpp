#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, ans=1;
bool check(ll x) {
  ll g=0, day=0;
  while (g<n && day<k) {
    ll y = (n-g)/x;
    if (y<m) {
      ll daysleft = k - day;
      return (g + daysleft*m >= n);
    }
    ll numdays = (n-g - x*y)/y + 1;
    if (day + numdays > k) numdays = k-day;
    g += y * numdays;
    day += numdays; 
  }
  return g >= n;
}
int main() {
  cin >> n >> k >> m; 
  ll l=1, r=1e12;
  while (l<=r) {
    ll mid=(l+r)/2; 
    if (check(mid)) {
      ans = mid, l = mid+1;
    } else {
      r = mid-1;
    }
  }
  cout << ans << '\n';
}