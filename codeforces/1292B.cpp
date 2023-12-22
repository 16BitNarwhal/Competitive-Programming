#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
#define x first
#define y second
ll t;
pi nodes[60], a, b, start;
ll dis(pi a1, pi b1) {
  return abs(a1.x - b1.x) + abs(a1.y - b1.y);
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  pi cur;
  cin >> cur.x >> cur.y >> a.x >> a.y >> b.x >> b.y;
  cin >> start.x >> start.y >> t;
  int n=0;
  for (int i=1;i<60;i++) {
    if (dis(cur, start) <= t) nodes[n++] = cur;
    cur.x = cur.x * a.x + b.x;
    cur.y = cur.y * a.y + b.y;
    if (cur.x > 2e16 || cur.y > 2e16) break;
  }
  int ans=0;
  for (int i=0;i<n;i++) {
    for (int j=i;j<n;j++) {
      ll len = dis(nodes[i], nodes[j]);
      ll left = dis(start, nodes[i]);
      ll right = dis(start, nodes[j]);
      if (len + min(left, right) <= t) {
        ans = max(ans, j-i+1);
      }
    }
  }
  cout << ans << '\n';
}