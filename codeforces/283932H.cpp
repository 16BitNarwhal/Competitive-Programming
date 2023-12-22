#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cb, cs, cc;
int nb, ns, nc;
int pb, ps, pc;
ll bal;
bool check(ll x) {
  ll reqb = x * cb;
  ll reqs = x * cs;
  ll reqc = x * cc;
  ll cost=0;
  if (reqb - nb > 0) cost += (reqb - nb) * pb;
  if (reqs - ns > 0) cost += (reqs - ns) * ps;
  if (reqc - nc > 0) cost += (reqc - nc) * pc;
  return cost <= bal;
}
int main() {
  string s;cin>>s;
  for (char c:s) {
    if (c=='B') cb++;
    else if (c=='S') cs++;
    else if (c=='C') cc++;
  }
  cin >> nb >> ns >> nc;
  cin >> pb >> ps >> pc;
  cin >> bal;
  ll l=0, r=1, ans=0;
  while (check(r)) r*=2;
  while (l<=r) {
    ll m = l + (r-l)/2;
    if (check(m)) {
      ans=m;l=m+1;
    } else {
      r=m-1;
    }
  }
  cout << ans << '\n';
}