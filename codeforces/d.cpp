#include <bits/stdc++.h>
using namespace std;
const int MM = 2e6+2;
typedef long long ll;
ll cnt[MM], pre[MM];
int main() {
  ll n, C;
  cin >> n >> C;
  for (int i=0;i<n;i++) {
    int x; cin >> x;
    cnt[x]++;
  }
  for (int i=0;i<2*C;i++) {
    pre[i] = (i>0?pre[i-1]:0) + cnt[i%C];
  }
  ll sum=0;
  for (int i=0;i<C;i++) {
    ll x = (pre[C/2 + i] - pre[i]);
    ll y = cnt[i];
    sum += x*(x-1)/2 * y;
    sum += x * y*(y-1)/2;
    sum += y*(y-1)*(y-2)/6;
  }
  if (C%2==0) {
    for (int i=0;i<C/2;i++) {
      ll x = cnt[i], y = cnt[C/2+i];
      sum -= x*(x-1)/2 * y;
      sum -= x * y*(y-1)/2;
    }
  }
  cout << n*(n-1)*(n-2)/6 - sum << '\n';
}
