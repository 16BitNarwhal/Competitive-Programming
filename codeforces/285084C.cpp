#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
ll n, k, a[MM], b[MM];
bool check(ll x) {
  ll sum = 0;
  for (int i=0;i<n;i++) {
    ll l=0,r=n-1,j=-1;
    while (l<=r) {
      ll m = l + (r-l)/2;
      if (a[i] + b[m] < x) {
        j = m;
        l = m+1;
      } else r = m-1;
    } 
    sum += j + 1;
  } 
  return sum < k;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<n;i++) cin >> b[i];
  sort(a, a+n);
  sort(b, b+n);
  ll l=0, r=1e10, ans=-1; 
  while (l<=r) {
    ll m = l + (r-l)/2;
    if (check(m)) {
      ans = m;
      l = m+1;
    } else r=m-1;
  }
  cout << ans << '\n';
}