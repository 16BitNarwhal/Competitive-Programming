#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
bool check(ll x) {
  x -= min(a,b);
  return (x/a + x/b) >= (n-1);
}
int main() {
  cin>>n>>a>>b;
  ll l=min(a,b),r=l,ans=-1;
  while (!check(r)) r*=2;
  while (l<=r) {
    ll m = l + (r-l)/2;
    if (check(m)) {
      ans=m; r=m-1;
    } else l=m+1;
  }
  cout << ans << '\n';
}