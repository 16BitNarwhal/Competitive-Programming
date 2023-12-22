#include <bits/stdc++.h>
using namespace std;
const int MM = 4e5+4;
int n, ar[MM], st[MM][20];
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
// sparse table
void build() {
  for (int i=1;i<=n;i++)
    st[i][0] = ar[i];
  for (int i=1;(1<<i)<=n;i++) {
    for (int j=1;j+(1<<(i-1))<=n;j++)
      st[j][i] = gcd(st[j][i-1], st[j+(1<<(i-1))][i-1]);
  }
}
int query(int l, int r) {
  int k = log2(r-l+1);
  return gcd(st[l][k], st[r-(1<<k)+1][k]);
}
bool good(int x) {
  for (int i=1;i<=n/2;i++) {
    if (query(i, i+x) != 1) return false;
  }
  return true;
}
int main() {
  int t;cin>>t;
  while (t--) {
    cin >> n;
    for (int i=1;i<=n;i++) cin >> ar[i];
    int g = ar[1];
    for (int i=1;i<=n;i++) g = gcd(g, ar[i]);
    for (int i=1;i<=n;i++) {
      ar[i] /= g;
      ar[n+i] = ar[i];
    }
    n *= 2;
    build();
    int l=0, r=n/2-1, ans=n/2;
    while (l<=r) {
      int m = l + (r-l)/2;
      if (good(m)) {
        ans = m;
        r = m-1;
      } else l = m+1;
    }
    cout << ans << '\n';
  }
}