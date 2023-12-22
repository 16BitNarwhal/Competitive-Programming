#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  if (1LL*k*(k-1) < n) {
    cout << "NO\n";
    return 0;
  }
  bool flip=false;
  int i=1, j=2;
  cout << "YES\n";
  while (n--) {
    if (flip) {
      cout << j << ' ' << i << '\n';
      j++;
      if (j>k) {
        i++;
        j=i+1;
      }
    } else {
      cout << i << ' ' << j << '\n';
    }
    flip = !flip;
  }
}