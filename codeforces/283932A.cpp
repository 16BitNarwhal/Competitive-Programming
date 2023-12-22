#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w,h,n;
bool check(ll x) {
  return (x/w)*(x/h) >= n;
}
int main() {
  cin>>w>>h>>n;
  ll l=0,r=1,ans;
  while (!check(r)) r*=2;
  while (l<=r) {
    ll m = l + (r-l)/2;
    if (check(m)) {
      ans=m;
      r=m-1;
    } else {
      l=m+1;
    }
  }
  cout << ans << '\n';
}
