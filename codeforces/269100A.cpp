// i have no idea what i did but it works
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
struct thing {
  int l, r, idx;
  bool operator<(const thing &o) const {
    if (l==o.l) return r < o.r;
    return l < o.l;
  }
} ar[MM];
int n, p[MM], c[MM];
string s;
int main() {
  cin >> s;
  s += '$';
  n = s.size();
  for (int i=0;i<n;i++) {
    ar[i] = {s[i], 0, i};
  }
  sort(ar, ar+n);
  for (int k=0;(1<<k)<n;k++) {
    for (int i=0;i<n;i++) {
      if (i==0) c[ar[i].idx]=0;
      else {
        if (ar[i].l == ar[i-1].l && ar[i].r == ar[i-1].r)
          c[ar[i].idx] = c[ar[i-1].idx];
        else 
          c[ar[i].idx] = c[ar[i-1].idx]+1;
      }
    }
    for (int i=0;i<n;i++) {
      ar[i].l = c[ar[i].idx];
      ar[i].r = c[(ar[i].idx + (1<<k)) % n];
    }
    sort(ar, ar+n);
  }
  for (int i=0;i<n;i++) {
    cout << ar[i].idx << ' ';
  }
}