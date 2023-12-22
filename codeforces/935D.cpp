#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5 + 5, mod = 1e9+7;
int n, m;
ll a[MM], b[MM];
ll qpow(ll a, ll b) { return b==0?1:(b&1?a:1)*qpow(a*a%mod, b>>1)%mod; }
ll inv(ll a) { return qpow(a, mod-2); }
ll mul(ll a, ll b) { return a*b%mod; }
ll add(ll a, ll b) { return (a+b+mod)%mod; }
ll P(ll i) {
  if (i==n) return 0;
  if (a[i]==0 && b[i]==0) // p(i+1)/m + (m-1)/(2m)
    return add(mul(P(i+1), inv(m)), mul(m-1, inv(mul(2,m))));
  if (a[i]==0) // p(i+1)/m + (m-b[i])/m
    return add(mul(P(i+1), inv(m)), mul(m-b[i], inv(m)));
  if (b[i]==0) // p(i+1)/m + (a[i]-1)/m
    return add(mul(P(i+1), inv(m)), mul(a[i]-1, inv(m)));
  if (a[i]>b[i]) return 1;
  if (a[i]<b[i]) return 0;
  if (a[i]==b[i]) return P(i+1);
}
int main() {
  cin>>n>>m;
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<n;i++) cin >> b[i];
  cout << P(0) << '\n';
}
