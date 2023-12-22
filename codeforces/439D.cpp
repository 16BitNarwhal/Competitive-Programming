#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int n, m;
ll a[MM], b[MM];
ll f(ll x) {
  ll cost=0;
  for (int i=0;i<n;i++) 
    cost += max(x - a[i], 0LL);
  for (int i=0;i<m;i++)  
    cost += max(b[i] - x, 0LL);
  return cost;
}
void bsearch() {
  ll l=0,r=1,ans=-1;
  while (f(r) > f(r+1)) r*=2;
  while (l<=r) { 
    ll m = l + (r-l)/2;
    if (f(m) <= f(m+1)) {
      ans = m;
      r = m-1;
    } else {
      l = m+1;
    }
  } 
  cout << f(ans) << '\n';
}
void tsearch() {
  ll l=0,r=2e9,ans=-1;
  while (l<=r) {
    ll m1 = l + (r-l)/3;
    ll m2 = r - (r-l)/3;
    if (f(m1) <= f(m2)) {
      ans = m1;
      r = m2 - (r==m2); 
    } else {
      l = m1 + (l==m1);
    }
  }
  cout << f(ans) << '\n';
}
int main() {
  cin >> n >> m;
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<m;i++) cin >> b[i];
  tsearch();
}