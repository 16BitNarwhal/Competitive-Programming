#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2, mod = 1e9+7;
int N, K, ar[MM];
ll fac[MM], inv[MM];
ll qpow(ll a, ll b) { return (b==0)?1:(b&1?a:1)*qpow(a*a%mod,b>>1)%mod; }
void init() {
  fac[0] = inv[0] = 1;
  for (int i=1;i<=N;i++) fac[i] = i * fac[i-1] % mod;
  for (int i=1;i<=N;i++) inv[i] = qpow(fac[i], mod-2);
}
ll choose(int n, int k) { return fac[n]*inv[k]%mod *inv[n-k]%mod; }
int main() {
  cin >> N >> K;
  init();
  for (int i=1;i<=N;i++) cin>>ar[i];
  sort(ar+1, ar+N+1);
  ll ans = 0;
  for (int i=K;i<=N;i++) {
    ans = (ans + ar[i]*choose(i-1,K-1)%mod)%mod;
  }
  cout << ans << '\n';
}