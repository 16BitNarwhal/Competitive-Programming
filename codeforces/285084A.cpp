#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
ll L[51], R[51];
bool check(ll x) {
  ll sum=0;
  for (int i=0;i<n;i++) {
    if (x >= L[i]) 
      sum += min(x, R[i]+1) - L[i];
  }
  return sum <= k;
}
int main() {
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> L[i] >> R[i];
  ll l=-2e9, r=2e9, ans=-1;
  while (l<=r) {
    ll m = l + (r-l)/2;
    if (check(m)) {
      ans = m;
      l = m+1;
    } else r=m-1;
  }
  cout << ans << '\n';

}