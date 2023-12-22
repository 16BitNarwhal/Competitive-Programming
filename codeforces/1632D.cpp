#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2, prime = 1e9+7;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int ar[MM], seg[3*MM];
void build(int i, int l, int r) {
  if (l==r) {
    seg[i] = ar[l];
    return;
  }
  int mid = (l+r)/2;
  build(i*2, l, mid);
  build(i*2+1, mid+1, r);
  seg[i] = gcd(seg[i*2], seg[i*2+1]);
}
void update(int i, int l, int r, int pos, int val) {
  if (l==r) {
    seg[i] = val;
    return;
  }
  int mid = (l+r)/2;
  if (pos<=mid) update(i*2, l, mid, pos, val);
  else update(i*2+1, mid+1, r, pos, val);
  seg[i] = gcd(seg[i*2], seg[i*2+1]);
}
int qry(int i, int l, int r, int ql, int qr) {
  if (ql<=l && r<=qr) return seg[i];
  int mid = (l+r)/2;
  if (qr<=mid) return qry(i*2, l, mid, ql, qr);
  if (ql>mid) return qry(i*2+1, mid+1, r, ql, qr);
  return gcd(qry(i*2, l, mid, ql, mid), qry(i*2+1, mid+1, r, mid+1, qr));
}
int main() {
  int n;cin>>n;
  for (int i=0;i<n;i++) {
    cin >> ar[i];
  }
  build(1, 0, n-1);
  int prev=0, cnt=0;
  for (int i=0;i<n;i++) {
    int l=prev, r=i, res=-1;
    while (l<=r) {
      int m = (l+r)/2;
      if (qry(1, 0, n-1, m, i) >= i+1-m) {
        r=m-1;
        res=m;
      } else l=m+1;
    }
    if (qry(1, 0, n-1, l, i) == i+1-res) {
      prev=i+1; cnt++;
    }
    cout << cnt << ' ';
  }
}