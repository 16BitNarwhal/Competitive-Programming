#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5+2;
struct thing {
  int l, r, idx;
  bool operator<(const thing &o) const {
    if (l==o.l) return r < o.r;
    return l < o.l;
  }
} ar[MM];
int n, p[MM], c[MM];
string t;
void build() {
  t += '$';
  n = t.size();
  for (int i=0;i<n;i++) 
    ar[i] = {t[i], 0, i};
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
  for (int i=0;i<n;i++) p[i] = ar[i].idx;
}
int q;
string s;
int check(int idx) {
  int m = s.length();
  for (int i=0;i<m;i++) {
    if (s[i] < t[(p[idx]+i)%n])
      return -1;
    else if (s[i] > t[(p[idx]+i)%n])
      return 1;
  }
  return 0; // equal
}
int main() {
  cin >> t;
  build();
  cin >> q;
  while (q--) {
    cin>>s;
    int l=0, r=n-1, lans=-1, rans=-1;
    while (l<=r) {
      int m = l+(r-l)/2;
      if (check(m) <= 0) {
        lans = m;
        r = m-1;
      } else {
        l = m+1;
      }
    }
    l=0, r=n-1;
    while (l<=r) {
      int m = l+(r-l)/2;
      if (check(m) >= 0) {
        rans=m;
        l = m+1;
      } else {
        r = m-1;
      }
    }
    if (lans <= rans && check(lans)==0 && check(rans)==0) {
      cout << rans - lans + 1 << '\n';
    } else {
      cout << "0\n";
    }
  }
}