#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
int n, m;
ll qpow(ll a, ll b) { return (b==0?1: (b&1?a:1)*qpow(a*a%mod,b/2)%mod); }
int main() {
  cin >> n >> m;
  ll x = qpow(2, m) -1;
  cout << qpow(x, n) << '\n';
}