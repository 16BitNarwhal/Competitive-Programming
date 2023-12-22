#include <bits/stdc++.h>
using namespace std;
struct pt {
  int x,y;
  bool operator < (const pt &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
};
map<pt, set<pt>> mp;
map<int, int> cntX, cntY;
void no() {
  cout << "NO\n";
  exit(0);
}
int main() {
  for (int i=0;i<4;i++) {
    pt a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    mp[a].insert(b); 
    mp[b].insert(a);
    cntX[a.x]++; cntX[b.x]++;
    cntY[a.y]++; cntY[b.y]++;
    if (a.x!=b.x && a.y!=b.y) no();
    if (a.x==b.x && a.y==b.y) no();
  }
  if (mp.size() != 4) no();
  for (auto [p, v] : mp) {
    if (v.size() != 2) no();
  }
  if (cntX.size() != 2) no();
  for (auto [x, c] : cntX) {
    if (c != 4) no();
  }
  if (cntY.size() != 2) no();
  for (auto [y, c] : cntY) {
    if (c != 4) no();
  }
  cout << "YES\n";
}