#include <bits/stdc++.h>
using namespace std;
int n, t, k;
bool check(int pos) {
  cout << "? 1 " << pos << '\n';
  cout.flush();
  int x; cin >> x;
  return pos - x < k;
}
int main() {
  cin >> n >> t >> k;
  int l = 1, r = n;
  while (l <= r) {
    int m = (l+r)/2;
    if (check(m)) l = m+1;
    else r = m-1;
  }
  cout << "! " << l << '\n';
}