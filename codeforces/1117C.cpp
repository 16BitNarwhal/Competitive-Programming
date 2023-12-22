#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
struct pt {
  ll x, y;
  pt operator+(const pt& p) const {
    return {x+p.x, y+p.y};
  }
  pt operator-(const pt& p) const {
    return {x-p.x, y-p.y};
  }
  pt operator*(const ll& k) const {
    return {x*k, y*k};
  }
} start, endd, mvt[MM];
int n;
bool check(ll x) {
  ll cycles = x / n;
  ll rem = x % n;
  pt res = start + mvt[n]*cycles + mvt[rem];
  pt left = endd - res;
  ll len = abs(left.x) + abs(left.y);
  return len <= x;
}
int main() {
  cin >> start.x >> start.y >> endd.x >> endd.y;
  cin >> n;
  mvt[0] = {0,0};
  for (int i=1;i<=n;i++) {
    char c;cin>>c;
    mvt[i] = mvt[i-1];
    if (c=='U') mvt[i].y++;
    else if (c=='D') mvt[i].y--;
    else if (c=='L') mvt[i].x--;
    else if (c=='R') mvt[i].x++;
  }
  pt tmp = endd - start;
  ll l=0, r=2e18;
  ll ans=-1;
  while (l<=r) {
    ll m = l + (r-l)/2;
    if (check(m)) {
      ans = m;
      r = m-1;
    } else l = m+1;
  }
  cout << ans << '\n';
}