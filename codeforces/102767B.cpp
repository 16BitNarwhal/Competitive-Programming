#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
ll qpow(ll a, ll b) { return b==0?1:(b&1?a:1)*qpow(a*a%mod,b>>1) % mod; }
ll mul(ll a, ll b) { return (a*b)%mod; }
int main() {
  int t;cin>>t;
  while(t--) {
    ll n, x;
    cin >> n >> x;
    ll ans = mul(x, qpow(2, n)-1);
    cout << ans << '\n';
  }
}