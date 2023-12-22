#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7, MM = 1e6+2;
ll fac[MM], inv[MM];
ll qpow(ll a, ll b) { return b==0?1:(b%2?a:1)*qpow(a*a%mod, b/2)%mod; }
void init() {
  fac[0] = 1;
  for (ll i=1;i<MM;i++) fac[i]=(fac[i-1]*i)%mod;
  for (ll i=0;i<MM;i++) inv[i]=qpow(fac[i], mod-2);
}
bool good(ll x, ll a, ll b) {
  if (x==0) return true;
  if (x%10 == a || x%10 == b) 
    return good(x/10, a, b);
  return false;
}
ll C(int n, int k) { return fac[n]*inv[k]%mod*inv[n-k]%mod; }
int main() {
  init();  
  int a, b, n;
  cin>>a>>b>>n;
  ll ans=0;
  for (int i=0;i<=n;i++) {
    ll x = a*i + b*(n-i);
    if (good(x, a, b)) {
      ans = (ans + C(n, i)) % mod;
    }
  }
  cout << ans << '\n';
}