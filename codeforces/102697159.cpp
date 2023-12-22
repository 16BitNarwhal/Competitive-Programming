#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fac(ll n) {
  ll res = 1;
  for (ll i=2;i<=n;i++) 
    res *= i;
  return res;
}
ll qpow(ll a, ll b) { return b==0?1:(b&1?a:1)*qpow(a*a,b>>1); }
ll C(ll n, ll k) { return fac(n)/fac(k)/fac(n-k); }
int main() {
  int n;cin>>n;
  cout << C(n, n/2) << '\n';
}