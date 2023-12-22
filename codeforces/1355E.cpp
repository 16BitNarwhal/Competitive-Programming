#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int n;
ll a, r, m, ar[MM];
ll calc(ll h) {
  ll aa=0, rr=0;
  for (int i=0;i<n;i++) {
    aa += max(h - ar[i], 0LL);
    rr += max(ar[i] - h, 0LL);
  }
  if (a+r < m) {
    return aa*a + rr*r;
  } else {
    ll mm = min(aa, rr);
    aa -= mm;
    rr -= mm;
    return aa*a + rr*r + mm*m;
  }
}
int main() {
  cin >> n >> a >> r >> m;
  for (int i=0;i<n;i++) cin >> ar[i];
  ll l=0, r=1e9, ans=1e18;
  while (l+3<r) {
    ll m1 = l + (r-l)/3;
    ll m2 = r - (r-l)/3;
    if (calc(m1) < calc(m2)) {
      r = m2;
    } else {
      l = m1;
    }
  }
  for (int i=l;i<=r;i++) {
    ans = min(ans, calc(i)); 
  }
  cout << ans << '\n';
} 