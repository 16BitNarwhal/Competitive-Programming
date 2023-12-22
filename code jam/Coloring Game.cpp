#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  for (int t=1;t<=T;t++) {
    int n; cin >> n;
    int cycles = n/5; // full cycles of len 5: BWWJW
    cout << "Case #" << t << ": ";
    if (n%5==0) {
      cout << cycles << '\n';
    } else {
      cout << cycles+1 << '\n';
    }
  }
}
