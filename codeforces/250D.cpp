#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int MM = 1e5+2;
int n, m, a, b;
ld A[MM], B[MM], l[MM];
ld dist(ld x1, ld y1, ld x2, ld y2) {
  return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
ld calc(int i, int j) {
  return dist(0,0,a,A[i]) + dist(a,A[i],b,B[j]) + l[j];
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> a >> b;
  for (int i=0;i<n;i++) cin>>A[i];
  for (int i=0;i<m;i++) cin>>B[i];
  for (int i=0;i<m;i++) cin>>l[i];
  ld best=1e18;
  int ansi=-1, ansj=-1;
  for (int j=0;j<m;j++) {
    int l=0, r=n-1;
    while (l<r-5) {
      int m = l + (r-l)/2;
      if (calc(m, j) < calc(m+1, j)) r = m;
      else l = m;
    }
    for (int i=l;i<=r;i++) {
      ld d = calc(i, j);
      if (d < best) {
        best = d;
        ansi = i+1;
        ansj = j+1;
      }
    }
  }
  cout << ansi << ' ' << ansj << '\n';
}