#include <bits/stdc++.h>
using namespace std;
double sx, sy, sz, x, y, z;
void rotH() {
  swap(x, y);
  y *= -1;
}
void rotV() {
  swap(x, z);
  z *= -1;
}
double dist() {
  return sqrt(x * x + y * y + z * z);
}
int main() {
  cin >> sx >> sy >> sz >> x >> y >> z;     
  x -= sx;
  y -= sy;
  z -= sz;
  double ans = dist();
  while (1) {
    double d; cin >> d;
    double nx = x-d;
    if ((x<=0 && nx>=0) || (x>=0 && nx<=0)) {
      x = 0;
      ans = min(ans, dist());
    }
    x = nx;
    ans = min(ans, dist());
    char dir; cin >> dir;
    if (dir == 'L') {
      rotH();
    } else if (dir == 'R') {
      rotH();
      rotH();
      rotH();
    } else if (dir == 'U') {
      rotV();
    } else if (dir == 'D') {
      rotV();
      rotV();
      rotV();
    } else {
      break;
    }
  }
  cout << setprecision(2) << fixed;
  cout << ans << '\n';
}