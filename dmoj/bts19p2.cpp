#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, V, H, T;
  cin>>X>>Y>>V>>H>>T;
  
  for (int a=0;a<T;a++) {
    int b = T-1-a;
    int x = 2*a + b;
    int y = a + 2*b;
    if (x>=X && y>=Y) {
      cout << "YES\n"; return 0;
    }
  }
  cout << "NO\n";
}