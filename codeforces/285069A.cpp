#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
typedef long double ld;
int n, d, m[MM], L, R;
ld ar[MM], p[MM];
pair<int,int> check(ld x) {
  p[0] = ar[0] - x;
  m[0] = 0;
  for (int i=1;i<n;i++) {
    p[i] = p[i-1] + (ar[i] - x);
    if (p[i] < p[m[i-1]]) m[i] = i;
    else m[i] = m[i-1];
  }
  if (p[d-1] >= 0) return {0,d-1};
  for (int i=d;i<n;i++) {
    if (p[i] >= 0) return {0, i};
    if (p[i] >= p[m[i-d]])
      return {m[i-d]+1, i};
  }
  return {-1,-1};
}
int main() {
  cin >> n >> d;
  for (int i=0;i<n;i++) cin >> ar[i];
  ld l=0,r=1;
  pair<int,int> ans; 
  while (check(r).first != -1) r*=2;
  while (r-l > 1e-6) {
    ld m = l + (r-l)/2;
    pair<int,int> tmp = check(m);
    if (tmp.first != -1) {
      ans = tmp;
      l=m;
    } else {
      r=m;
    }
  }
  cout << ans.first+1 << ' ' << ans.second+1 << '\n';
}
