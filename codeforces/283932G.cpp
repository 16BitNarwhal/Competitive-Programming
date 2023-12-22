#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 51;
ll n,k,a[MM];
bool check(ll x) {
  ll sum=0;
  for (int i=0;i<n;i++) {
    sum += min(a[i], x);
  }
  return sum >= x*k;
}
int main() {
  cin >> k >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  ll l=0,r=1,ans=0;
  while (check(r)) r*=2;
  while (l<=r) {
    ll m = l + (r-l)/2;
    if (check(m)) {
      ans = m;
      l = m+1;
    } else {
      r = m-1;
    }
  }
  cout << ans << '\n';
}