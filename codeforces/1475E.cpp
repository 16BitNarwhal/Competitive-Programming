#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1001, mod = 1e9+7;
int a[MM];
ll fac[MM], inv[MM];
ll qpow(ll a, ll b) { return (b==0 ? 1 : ((b&1)?a:1)*qpow(a*a%mod, b/2)%mod); }
ll C(ll n, ll r) { return fac[n] * inv[r] % mod * inv[n-r] % mod; }
int main() { 
  ios::sync_with_stdio(0); cin.tie(0);
  fac[0] = inv[0] = 1;
  for (int i=1;i<=1000;i++) fac[i] = (fac[i-1] * i) % mod;
  for (int i=1;i<=1000;i++) inv[i] = qpow(fac[i], mod-2);
  
  int t;cin>>t;
  while(t--) {
    int n,k;cin>>n>>k;
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a, a+n);
    int cnt = count(a, a+n, a[n-k]);
    int x = 0;
    for (int i=n-k;i<n;i++) {
      if (a[i] == a[n-k]) x++;
      else break;
    } 
    cout << C(cnt, x) << '\n';
  }
}