#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
struct thing {
  int l, r, idx;
  bool operator<(const thing &o) const {
    if (l==o.l) return r<o.r;
    return l < o.l;
  }
} ar[MM];
int n, p[MM], c[MM];
string s;
void build() {
  s += '$';
  n = s.size();
  for (int i=0;i<n;i++) 
    ar[i] = {s[i], 0, i}; 
  sort(ar, ar+n);
  for (int k=0;(1<<k)<n;k++) {
    for (int i=0;i<n;i++) {
      if (i==0) c[ar[i].idx] = 0;
      else {
        if (ar[i].l==ar[i-1].l && ar[i].r==ar[i-1].r)
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
string t; 
int check(int idx) {
  int m = t.size();
  for (int i=0;i<m;i++) {
    int x = (p[idx] + i) % n;
    if (t[i] < s[x]) 
      return -1;
    else if (t[i] > s[x])
      return 1;
  }
  return 0;
}
int main() { 
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> s;
  build();
  int q;cin>>q;
  while (q--) {
    cin >> t;
    int l=0, r=n-1, L=-1, R=-1;
    while (l<=r) {
      int m = l + (r-l)/2;
      if (check(m) >= 0) {
        R=m;
        l=m+1;
      } else {
        r=m-1;
      }
    }
    l=0, r=n-1;
    while (l<=r) {
      int m = l + (r-l)/2;
      if (check(m) <= 0) {
        L=m;
        r=m-1;
      } else {
        l=m+1;
      }
    }
    int k;cin>>k;
    if (L==-1 || R==-1 || R-L+1 < k) {
      cout << "-1\n";
      continue;
    }
    vector<int> res;
    for (int i=L;i<=R;i++) {
      res.push_back(p[i]+1);
    }
    sort(res.begin(), res.end());
    cout << res[k-1] << '\n';
  }
} 