#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2, mod=1e9+7;
bool can[MM];
int ar[MM];
ll dp[MM], sum[MM];
ll qpow(ll a, ll b) { return b?qpow(a*a%mod, b/2)*(b&1?a:1)%mod : 1; }
map<int, bool> mp;
bool check(int x) {
  int b = x; 
  if (mp[b]) return true; 
  while (b > 0) { 
    if (b&1) {
      b >>= 1;
    } else if ((b&3)==0) {
      b >>= 2;
    } else {
      return false;
    }
    if (mp[b]) return true;
  } 
  return false;
}
int main() {
  int n, p;
  cin >> n >> p;
  for (int i=0;i<n;i++) { 
    cin >> ar[i];
  }
  sort(ar, ar+n);
  set<int> start;
  for (int i=0;i<n;i++) {
    if (!check(ar[i])) { 
      mp[ar[i]]=true;
      start.insert(ar[i]);
    } 
  }
  dp[1] = 1;
  sum[1] = 1;
  for (int i=2;i<MM;i++) {
    dp[i] = (dp[i-2] + dp[i-1]) % mod;
    sum[i] = (sum[i-1] + dp[i]) % mod;
  }
  ll ans=0; 
  for (ll x : start) {
    int i = p-(int)log2(x);
    if (i<0) continue;
    ans += sum[i];
    ans %= mod;
  }
  cout << ans << '\n';
}