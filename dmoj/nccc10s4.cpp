// sad
// this also creates non polygon shape thingies
// check if all segments intersect in final polygon
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
struct pt {
  double x, y;
  bool operator<(const pt &p) const {
    if (abs(x - p.x) <= eps) return y<p.y;
    return x < p.x;
  }
  bool operator==(const pt &p) const {
    return abs(x - p.x) <= eps && abs(y - p.y) <= eps;
  }
  friend ostream& operator<<(ostream& os, const pt& p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
  }
} ar[12][2];
pt intersect(pt a, pt b, pt c, pt d) {
  double a1 = b.y - a.y;
  double b1 = a.x - b.x;
  double c1 = a1*a.x + b1*a.y;
  double a2 = d.y - c.y;
  double b2 = c.x - d.x;
  double c2 = a2*c.x + b2*c.y;
  double det = a1*b2 - a2*b1;
  if (det==0) 
    return {1e9, 1e9};
  double x = (b2*c1 - b1*c2)/det;
  double y = (a1*c2 - a2*c1)/det;
  return {x, y};
}
bool sameline(pt a, pt b, pt c) {
  double area = a.x*(c.y-b.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
  area /= 2;
  return abs(area) <= eps;
}
map<pt, vector<pt>> adj;
map<pt, bool> vis;
set<set<pt>> res;
int n;
void dfs(pt st, pt pa, pt u, int d) {
  if (d==n) return;
  vis[u] = true; 
  for (pt v : adj[u]) {
    if (sameline(pa, u, v)) continue;
    if (v==st && d==n-1) {
      set<pt> s;
      for (auto [p, q] : vis)
        if (q) s.insert(p);
      res.insert(s);
      vis[u] = false;
      return;
    }
    if (vis[v]) continue;
    dfs(st, pa, v, d+1);
  }
  vis[u] = false; 
}
int main() {
  cin>>n;
  for (int i=0;i<n;i++) {
    cin >> ar[i][0].x >> ar[i][0].y >> ar[i][1].x >> ar[i][1].y;
  }
  for (int i=0;i<n;i++) {
    vector<pt> v;
    for (int j=0;j<n;j++) {
      pt p = intersect(ar[i][0], ar[i][1], ar[j][0], ar[j][1]);
      if (p.x == 1e9) continue;
      v.push_back(p);
    }
    for (pt a : v) {
      for (pt b : v) {
        if (a==b) continue;
        adj[a].push_back(b);
      }
    }
  }
  for (auto [p, v] : adj) {
    dfs(p, {1e9,1e9}, p, 0);
  }
  int ans=0;
  for (auto s : res) {
    bool flag=true;
    for (pt a : s) { 
      for (pt b : s) {
        if (a==b) continue;
        for (pt c : s) {
          if (c==b || c==a) continue;
          if (sameline(a, b, c)) flag=false;
        }
      }
    }
    if (flag) {
      for (pt p : s) cout << p << ' ';
      cout << '\n';
    }
    if (flag) ans++;
  }
  cout << ans << '\n';
}