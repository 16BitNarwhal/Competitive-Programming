#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+2, mod = 998244353;
int n, cnt[MM];
vector<int> a[MM];
ll qpow(ll a, ll b) { return (b==0)?1: (b&1?a:1)*qpow(a*a%mod, b/2)%mod; }
ll inv(ll a) { return qpow(a, mod-2); }
ll mul(ll a, ll b) {return a*b%mod;}
int main() { 
  cin >> n;
  for (int i=0;i<n;i++) {
    int k;cin>>k;
    for (int j=0;j<k;j++) {
      int x;cin>>x;
      a[i].push_back(x);
      cnt[x]++;
    }
  }
  ll ans=0;
  for (int i=0;i<n;i++) {
    for (int j : a[i]) {
      ans = (ans + mul(mul(inv(a[i].size()), inv(n)),mul(cnt[j], inv(n)))) % mod;
    }
  }
  cout << ans << '\n';
}