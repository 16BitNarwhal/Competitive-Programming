#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C(ll n, ll k) { 
  ll res=1;
  for (ll i=n;i>n-k;i--) res *= i;
  for (ll i=2;i<=k;i++) res /= i;
  return res;
}
int main() { 
  ll n, k;
  cin >> n >> k; 
  ll ans=1;
  if (k>=2) ans += C(n, 2);
  if (k>=3) ans += 2 * C(n, 3);
  if (k>=4) ans += 9 * C(n, 4);
  cout << ans << '\n';
}