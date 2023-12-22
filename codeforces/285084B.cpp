#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
bool check(ll x) {
  ll sum=0;
  for (ll i=1;i<=n;i++)
    sum += min(x-1, i*n) / i; 
  return sum < k;
}
int main() {
  cin >> n >> k; 
  ll l=1, r=1e10, ans=-1;
  while (l<=r) {
    ll m = l + (r-l)/2;
    if (check(m)) {
      ans = m;
      l = m+1;
    } else r=m-1;
  }
  cout << ans << '\n';
}