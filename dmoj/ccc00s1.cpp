#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;cin>>x;
  int a, b, c;
  cin >> a >> b >> c;
  int cnt=0;
  while (x>0) {
    a++; x--; cnt++;
    if (a==35) {
      x += 30;
      a = 0;
    }
    if (x==0) break;
    b++; x--; cnt++;
    if (b==100) {
      x += 60;
      b = 0;
    }
    if (x==0) break;
    c++; x--; cnt++;
    if (c==10) {
      x += 9;
      c = 0;
    }
    if (x==0) break;
  }
  cout << "Martha plays " << cnt << " times before going broke.\n";
}