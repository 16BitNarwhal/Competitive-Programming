#include <bits/stdc++.h>
using namespace std;
const int MM = 132675;
struct rect { int x1,y1,x2,y2; } ar[MM], pre[MM], suf[MM];
int n;
rect intersect(rect a, rect b) {
  rect res;
  res.x1 = max(a.x1, b.x1);
  res.y1 = max(a.y1, b.y1);
  res.x2 = min(a.x2, b.x2);
  res.y2 = min(a.y2, b.y2); 
  return res;
}
bool valid(rect r) {
  return (r.x1 <= r.x2 && r.y1 <= r.y2);
}
int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> ar[i].x1 >> ar[i].y1 >> ar[i].x2 >> ar[i].y2;
    if (i) pre[i] = intersect(pre[i-1], ar[i]);
    else pre[i] = ar[i];
  }
  for (int i=n-1;i>=0;i--) {
    if (i<n-1) suf[i] = intersect(suf[i+1], ar[i]);
    else suf[i] = ar[i];
  }
  if (valid(suf[1])) {
    cout << suf[1].x1 << ' ' << suf[1].y1 << '\n';
    return 0;
  }
  if (valid(pre[n-2])) {
    cout << pre[n-2].x1 << ' ' << pre[n-2].y1 << '\n';
    return 0;
  }
  for (int i=1;i<n-1;i++) {
    rect a = intersect(pre[i-1], suf[i+1]);
    if (valid(a)) {
      cout << a.x1 << ' ' << a.y1 << '\n';
      return 0;
    }
  }
}