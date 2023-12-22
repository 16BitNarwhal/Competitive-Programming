#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    int ax, ay; cin>>ax>>ay;
    int bx, by; cin>>bx>>by;
    int fx, fy; cin>>fx>>fy;
    int plus=0;
    if (ax==bx && ax==fx && fy>=min(ay,by) && fy<=max(ay,by)) plus+=2;
    if (ay==by && ay==fy && fx>=min(ax,bx) && fx<=max(ax,bx)) plus+=2;
    cout << abs(bx-ax) + abs(by-ay) + plus << '\n';
  }
}