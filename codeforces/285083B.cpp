#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
typedef long long ll;
int n, k, ar[MM];
bool check(ll x) {
  int cnt=1;
  ll sum=0;
  for (int i=0;i<n;i++) {
    if (ar[i] > x) return 0;
    if (sum + ar[i] > x) {
      sum = ar[i];
      cnt++;
    } else {
      sum += ar[i];
    }
  }
  return cnt <= k;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>k;
  for (int i=0;i<n;i++) 
    cin>>ar[i];
  ll l=0,r=1,ans=-1;
  while (!check(r)) r*=2;
  while (l<=r) {
    ll m = l + (r-l)/2;
    if (check(m)) {
      ans = m;
      r = m-1;
    } else {
      l = m+1;
    }
  }
  cout << ans << '\n';
}