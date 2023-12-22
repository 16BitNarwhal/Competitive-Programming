#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
ld C;
bool check(ld x) {
  return (x*x) + sqrt(x) >= C;
}
int main() {
  cin>>C;
  ld l=0, r=1;
  while (!check(r)) r*=2;
  while (r-l > 1e-7) {
    ld m = l + (r-l)/2;
    if (check(m)) r = m;
    else l = m;
  }
  cout << fixed << l << '\n';
}