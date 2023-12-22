#include <bits/stdc++.h>
using namespace std;
int cx, cy, dis;
bool check(int x, int y) {
  if (abs(x-cx) + abs(y-cy) <= dis) 
    return true;
  return false;
}
int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1;
  x2 = x1; y2 = y1;
  for (int i=0;i<3;i++) {
    int x,y;cin>>x>>y;
    x1 = min(x1, x);
    x2 = max(x2, x);
    y1 = min(y1, y);
    y2 = max(y2, y);
  }
  int left, btm, top, right;
  int x,y;cin>>x>>y;
  left = right = x;
  btm = top = y;
  for (int i=0;i<3;i++) {
    cin>>x>>y;
    left = min(x,left);
    right = max(x, right);
    btm = min(y, btm);
    top = max(y, top);
  }
  cx = (left+right)/2;
  cy = (top+btm)/2;
  dis = (right-left)/2;
  for (int i=x1;i<=x2;i++) {
    for (int j=y1;j<=y2;j++) {
      if (check(i,j)) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
}