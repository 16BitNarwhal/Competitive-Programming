#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll phi(ll n) {
  ll ans = n;
  for (ll i=2; i*i<=n; i++) {
    if (n % i == 0) {
      while (n%i==0) n/=i;
      ans -= ans/i;
    }
  }
  if (n>1) ans -= ans/n;
  return ans;
}
int main() {
  int t;cin>>t;
  while(t--) {
    ll a, m;
    cin>>a>>m;
    ll g = gcd(a, m);
    cout << phi(m/g) << '\n';
  }
}