#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
int n, m, a[1111];
ll fac[1111], inv[1111];
ll qpow(ll a, ll b) { return (b==0?1: (b&1?a:1)*qpow(a*a%mod, b/2)%mod); }
ll C(int n, int k) { return fac[n] * inv[k] % mod * inv[n-k] % mod; }
int main() {
  cin >> n >> m;
  m *= 2;
  fac[0] = 1;
  for (int i=1;i<1111;i++) fac[i] = fac[i-1] * i % mod;
  for (int i=0;i<1111;i++) inv[i] = qpow(fac[i], mod-2);
  cout << C(n+m-1, m) << '\n';
  // a[1] = 1;
  // for (int i=1;i<=m;i++) {
  //   for (int j=1;j<=n;j++) {
  //     a[j] = (a[j-1] + a[j]) % mod;
  //   } 
  // }
  // int res=0;
  // for (int i=1;i<=n;i++) 
  //   res= (res+a[i]) % mod;
  // cout << res << '\n';
}