#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b; cin>>a>>b;
  int y = (b-2*a)/2;
  int x = a-y;
  if (x>=0 && y>=0 && x+y==a && 2*x+4*y==b) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}