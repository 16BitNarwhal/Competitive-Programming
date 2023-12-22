#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
typedef long double ld;
typedef pair<ld,ld> pi;
ld n, X[MM], V[MM];
pi intersect(pi a, pi b) { 
  return {max(a.first, b.first), min(a.second, b.second)};
}
bool check(ld t) {
  pi res = {X[0]-V[0]*t, X[0]+V[0]*t};
  for (int i=0;i<n;i++) {
    res = intersect(res, {X[i]-V[i]*t, X[i]+V[i]*t});
  }
  return res.first <= res.second;
}
int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> X[i] >> V[i];
  }
  ld l=0, r=1e9; 
  while (r-l > 1e-6) {
    ld m = l + (r-l)/2;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << fixed << l << '\n';
}