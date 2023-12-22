#include <bits/stdc++.h>
using namespace std; 
int main() {
  int n;cin>>n;
  int zero=0, one=1023;
  while (n--) {
    char op;cin>>op;
    int x;cin>>x;
    if (op=='|') {
      zero |= x;
      one |= x;
    } else if (op=='&') {
      zero &= x;
      one &= x;
    } else {
      zero ^= x;
      one ^= x;
    }
  }
  int to_zero=1023, to_one=0, flip=0;
  for (int i=0;i<10;i++) {
    if ((zero>>i) & 1) {
      if ((one>>i) & 1) { // 0->1, 1->1
        // set bit to 1
        to_one |= (1<<i);
      } else { // 0->1, 1->0
        // flip bit
        flip |= (1<<i);
      }
    } else {
      if ((one>>i) & 1) { // 0->0, 1->1
        // do nothing 
      } else { // 0->0, 1->0
        // set bit to 0
        to_zero ^= (1<<i);
      }
    }
  }
  cout << "3\n";
  cout << "| " << to_one << '\n';
  cout << "& " << to_zero << '\n';
  cout << "^ " << flip << '\n';
}