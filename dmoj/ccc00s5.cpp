#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int MM = 1002;
struct p { ld x, y; } a[MM];
int n;
set<int> res;
ld dist(p a, p b) {
  ld dx = a.x-b.x, dy = a.y-b.y;
  return dx*dx + dy*dy;
} 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i].x >> a[i].y; 
  for (ld x=0;x<=1000;x+=0.01) {
    p cur = {x, 0};
    ld mn = dist(cur, a[0]);
    for (int i=1;i<n;i++) mn=min(mn,dist(cur,a[i]));
    for (int i=0;i<n;i++) {
      if (abs(dist(cur,a[i])-mn) <= 1e-6) res.insert(i);
    }
  }
    
  cout << setprecision(2) << fixed;
  for (int i:res) {
    cout <<"The sheep at ("<<a[i].x<<", "<<a[i].y<<") might be eaten.\n";
  }
}