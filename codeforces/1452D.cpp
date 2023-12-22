#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+1, mod = 998244353;
ll F[MM];
ll gcd(ll a, ll b) { return (b==0 ? a : gcd(b, a%b)); }
ll qpow(ll a, ll b) { return (b==0 ? 1 : (b&1 ? a:1) * qpow(a*a%mod, b/2) % mod); }
int main() {  
  int n;cin>>n;
  F[1] = 1, F[2] = 1;
  ll x= 2 * min(n,2);
  for (int i=3;i<=n;i++) {
    F[i] = (F[i-1] + F[i-2]) % mod;
    x = x*2 % mod;
  }
  ll y = gcd(F[n], x); 
  cout << F[n]/y * qpow(x/y, mod-2) % mod;
}