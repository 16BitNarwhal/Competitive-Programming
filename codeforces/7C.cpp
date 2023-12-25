#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct foo {
  ll x, y, r;
};

// idk the normal impl D:
foo EEA(foo a, foo b) {
  if (b.r==0) return a;
  ll q = a.r / b.r;
  foo nxt;
  nxt.r = a.r % b.r;
  nxt.x = a.x - (b.x * q);
  nxt.y = a.y - (b.y * q);
  return EEA(b, nxt);
}

int main() {
  ll A, B, C;
  cin >> A >> B >> C;
  foo a = {1, 0, A};
  foo b = {0, 1, B};
  foo res = EEA(a, b);
  if (C % res.r != 0) {
    cout << "-1\n"; return 0;
  }
  ll q = (-C) / res.r;
  cout << res.x * q << ' ' << res.y * q << '\n';
}