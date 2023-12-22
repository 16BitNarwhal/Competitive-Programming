#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2, MOD = 998244353;
int a[MM], b[MM], cnt[MM], fen[MM];
ll fac[MM], inv[MM];
int get(int i) {
  int sum=0;
  for (;i>0;i-=i&-i) sum+=fen[i];
  return sum;
}
void add(int i, int v) {
  for (;i<MM;i+=i&-i) fen[i]+=v;
}
ll qpow(ll a, ll b) { return b==0?1:(b&1?a:1)*qpow(a*a%MOD, b>>1)%MOD; }
int main() {
  int n, m;
  cin >> n >> m;
  fac[0] = 1;
  for (int i=1;i<=n;i++) fac[i] = (fac[i-1]*i)%MOD;
  for (int i=0;i<=n;i++) inv[i] = qpow(fac[i], MOD-2);
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<m;i++) cin >> b[i];
  int N=0;
  for (int i=0;i<n;i++) {
    cnt[a[i]]++; 
    add(a[i], 1);
    N = max(N, a[i]);
  }
  ll div=1;
  for (int i=1;i<=N;i++) {
    div = (div * inv[cnt[i]])%MOD;
  }
  ll ans=0;
  int i;
  for (i=0;i<min(n,m);i++) {
    ans += fac[n-i-1] * div % MOD * get(b[i]-1) % MOD;
    ans %= MOD;
    if (cnt[b[i]]==0) break;
    div = div * cnt[b[i]] % MOD;
    cnt[b[i]]--;
    add(b[i], -1);
  }
  if (n<m && i==n) {
    ans = (ans+1)%MOD;
  }
  cout << ans << '\n';
}