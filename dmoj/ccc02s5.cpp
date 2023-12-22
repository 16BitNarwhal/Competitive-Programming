#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
ld w, h, sx, sy;
int main() {
  cin >> w >> h >> sx >> sy;
  ld slope = sy/(w-sx);
  for (int i=1;i<=100000;i++) {
    ld y = slope * (w*i - sx); 
    ld x = (h*i)/slope + sx; 
    int numH = (int)((y - (h/2))/h) + 1;
    int numW = (int)((x - (w/2))/w) + 1;
    ld a=numH * h, b=numW * w;
    if (abs(a-y)<5 || abs(b-x)<5) {
      if (abs(a-y)<5) {
        if (a != y) {
          cout << i-1 + (int)(y/h);
        } else {
          cout << i-1 + (int)(y/h) - 1;
        }
      } else {
        if (b != x) {
          cout << i-1 + (int)(x/w);
        } else {
          cout << i-1 + (int)(x/w) - 1;
        }
      }
      cout << '\n';
      return 0;
    }
  }
  cout << "0\n";
}