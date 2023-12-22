#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e5+2;
const ll mod = 1e9+7;
ll qpow(ll a, ll b) {
  return b==0?1:(b&1?a:1)*qpow(a*a%mod, b/2)%mod;
}
ll inv(ll a) {
  return qpow(a, mod-2);
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    int n,m;
    cin >>n>>m;
    unordered_map<ll,ll> freq;
    set<ll> s;
    for (int i=0;i<n;i++) {
      ll x; cin >> x; 
      freq[x]++;
      s.insert(x);
    }
    ll ans=0, cur=1, cnt=0, prev=-1;
    for (ll x : s) {
      if (x != prev+1) {
        cur=1;
        cnt=0;
      }
      cur = (cur * freq[x]) % mod; 
      cnt++;
      prev=x;
      if (cnt==m) {
        ans = (ans+cur)%mod;
        cur = (cur * inv(freq[x-m+1])) % mod;
        cnt--;
      }
    }
    cout << ans << '\n';
  }
}