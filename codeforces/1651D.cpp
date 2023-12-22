#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
struct pt {
  int x, y;
  bool operator<(const pt &rhs) const {
    if (x == rhs.x) return y < rhs.y;
    return x < rhs.x;
  }
} a[MM];
map<pt, int> dst, idx;
map<pt, pt> res;
int main() {
  int n;cin>>n;
  for (int i=0;i<n;i++) {
    cin >> a[i].x >> a[i].y; 
    idx[a[i]] = i+1;
  }
  queue<pt> q; 
  for (int i=0;i<n;i++) {
    int x=a[i].x, y=a[i].y;
    if (!idx[{x+1,y}]) {
      res[a[i]] = {x+1, y};
      dst[a[i]] = 1;
    }
    if (!idx[{x-1,y}]) {
      res[a[i]] = {x-1, y};
      dst[a[i]] = 1;
    }
    if (!idx[{x,y+1}]) {
      res[a[i]] = {x, y+1};
      dst[a[i]] = 1;
    }
    if (!idx[{x,y-1}]) {
      res[a[i]] = {x, y-1};
      dst[a[i]] = 1;
    }
    if (dst[a[i]]) {
      q.push(a[i]); 
    }
  }
  while (!q.empty()) {
    pt p = q.front();
    q.pop();
    int x = p.x, y = p.y;
    if (!dst[{x+1,y}] && idx[{x+1,y}]) {
      res[{x+1,y}] = res[p];
      dst[{x+1,y}] = dst[p]+1;
      q.push({x+1,y});
    }
    if (!dst[{x-1,y}] && idx[{x-1,y}]) {
      res[{x-1,y}] = res[p];
      dst[{x-1,y}] = dst[p]+1; 
      q.push({x-1,y});
    }
    if (!dst[{x,y+1}] && idx[{x,y+1}]) {
      res[{x,y+1}] = res[p];
      dst[{x,y+1}] = dst[p]+1; 
      q.push({x,y+1});
    }
    if (!dst[{x,y-1}] && idx[{x,y-1}]) {
      res[{x,y-1}] = res[p];
      dst[{x,y-1}] = dst[p]+1; 
      q.push({x,y-1});
    }
  }
  for (int i=0;i<n;i++) { 
    cout << res[a[i]].x << ' ' << res[a[i]].y << '\n';
  }
}

// for all points, if 1 empty neighbor, then d=1
// bfs the rest of points for distance and nearest point