#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5005, mod = 998244353; 
ll fac[MM], inv[MM];
ll qpow(ll a, ll b) { return b==0 ? 1 : (b&1?a:1) * qpow(a*a%mod, b/2) % mod;}
void init() {
  fac[0] = 1;
  for (int i=1;i<MM;i++) fac[i] = (fac[i-1] * i) % mod;
  for (int i=0;i<MM;i++) inv[i] = qpow(fac[i], mod-2);
}
ll C(ll n, ll k) {
  return fac[n] * inv[k] % mod * inv[n-k] % mod;
}
int main() {
  init();
  int n, k;
  cin >> n >> k;
  string s; cin >> s;
  int c1=0;
  for (int i=0;i<n;i++) c1 += (s[i]-'0');
  if (c1 < k) {
    cout << "1\n";
    return 0;
  }
  ll ans=1;
  for (int i=0;i<n;i++) {
    int cnt[2] = {0,0};
    cnt[s[i]-'0']++;
    for (int j=i+1;j<n;j++) {
      cnt[s[j]-'0']++;
      if (cnt[1] > k) continue;
      int c = cnt[1];
      if (s[i]=='0') c--;
      if (s[j]=='0') c--;
      ans = (ans + C(cnt[0]+cnt[1]-2, c)) % mod;
    }
  }
  cout << ans << '\n';
}