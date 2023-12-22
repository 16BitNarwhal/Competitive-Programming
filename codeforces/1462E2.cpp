#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2, mod=1e9+7;
int n, m, k, a[MM];
ll fac[MM], inv[MM];
ll qpow(ll a, ll b) { return (b==0 ? 1 : (b&1?a:1)*qpow(a*a%mod, b>>1) % mod); }
ll C(ll n, ll k) { 
  if (n < k) return 0;
  return fac[n] * inv[k] % mod * inv[n-k] % mod; 
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  fac[0] = inv[0] = 1;
  for (int i=1;i<MM;i++) fac[i] = fac[i-1] * i % mod;
  for (int i=1;i<MM;i++) inv[i] = qpow(fac[i], mod-2);
  int t;cin>>t;
  while(t--) {
    cin >> n >> m >> k;
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a, a+n); 
    int l=0, r=0;
    ll tot=0;
    for (;l<n;l++) {
      while (r<n-1 && a[r+1]-a[l] <= k) r++;
      tot += C(r-l, m-1);
    }
    cout << tot%mod << '\n';
  }
}