#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int n, ar[MM];
struct node { int l, r, v; } seg[3*MM];
int gcd(int a, int b) { return (b==0 ? a : gcd(b, a%b)); }
void build(int l, int r, int idx) {
  seg[idx].l = l; seg[idx].r = r;
  if (l==r) { seg[idx].v = ar[l]; return; }
  int m = (l+r)/2;
  build(l, m, 2*idx); 
  build(m+1, r, 2*idx+1);
  seg[idx].v = gcd(seg[2*idx].v, seg[2*idx+1].v);
}
void update(int pos, int val, int idx) {
  if (seg[idx].l == pos && seg[idx].r == pos) {
    seg[idx].v = val; return;
  }
  int m = (seg[idx].l + seg[idx].r) / 2;
  if (pos <= m)
    update(pos, val, 2*idx);
  else
    update(pos, val, 2*idx+1);
  seg[idx].v = gcd(seg[2*idx].v, seg[2*idx+1].v);
}
int main() {
  cin >> n;
  for (int i=1;i<=n;i++) cin>>ar[i];
  build(1, n, 1);
  int ans=0;
  for (int i=1;i<=n;i++) {
    int x = ar[i];
    if (i==1) update(i, ar[i+1], 1);
    else update(i, ar[i-1], 1);
    ans = max(ans, seg[1].v);
    ar[i] = x;
    update(i, ar[i], 1);
  }
  cout << ans << '\n';
}