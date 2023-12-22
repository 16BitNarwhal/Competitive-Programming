#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
bool check(ll x) { 
  return (k*(k-1)/2 - (k-x)*(k-x-1)/2 + 1) >= n;
}
int main() {
  cin >> n >> k;
  ll l=0,r=k,ans=-1;
  while (l<=r) {
    ll m = l + (r-l)/2;
    if (check(m)) {
      ans = m;
      r = m-1;
    } else {
      l = m+1;
    }
  }
  if (check(ans)) cout << ans << '\n';
  else cout << -1 << '\n';
}