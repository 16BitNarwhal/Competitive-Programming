#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+2, mod = 998244353;
int n, m;
ll fac[N], inv[N];
ll qpow(ll a, ll b) { return (b==0?1: (b&1?a:1) * qpow(a*a%mod, b/2) % mod); }
ll C(ll n, ll k) { return fac[n] * inv[k] % mod * inv[n-k] % mod; }
int main() { 
  fac[0] = 1;
  for (int i=1;i<N;i++) fac[i] = fac[i-1] * i % mod;
  for (int i=0;i<N;i++) inv[i] = qpow(fac[i], mod-2);

  cin >> n >> m;
  ll ans=0; 
  if (n>2)
    ans = C(m, n-1) * (n-2) % mod * qpow(2, n-3) % mod;
  cout << ans << '\n';
}

/*
C(m, n-1) <= # ways to pick n-1 (because 1 duplicate) of m numbers
(n-2) <= # ways to choose the duplicate (can't be max)
2^(n-3) <= # ways to choose positions (left / right) (can't be max or duplicates)
ans = product of ^^^
*/