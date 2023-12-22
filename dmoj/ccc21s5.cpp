#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 200000;
struct qry { int l, r, z; } Q[MM];
ll gcd(ll a, ll b) { return (b==0 ? a : gcd(b, a%b)); }
ll lcm(ll a, ll b) { return (a*b)/gcd(a,b); }
int n, m, Z[20][MM];
ll a[MM], st[MM][20];
int main() {
  cin>>n>>m;
  for (int i=0;i<m;i++) {
    int l, r, z; cin >> l >> r >> z;
    Q[i] = {l, r, z};
    Z[z][l]++; Z[z][r+1]--;
  }
  
  fill(a, a+n+1, 1);
  for (int z=1;z<=16;z++) {
    for (int i=1;i<=n;i++) {
      Z[z][i] += Z[z][i-1];
      if (Z[z][i]>0)
        a[i] = lcm(a[i], z);
    }
  }
  
  for (int i=1;i<=n;i++) st[i][0] = a[i];
  for (int j=1;j<20;j++) {
    for (int i=1; i+(1<<j) <=n+1;i++)
      st[i][j] = gcd(st[i][j-1], st[i + (1<<(j-1))][j-1]);
  }

  for (int i=0;i<m;i++) {
    int l=Q[i].l, r=Q[i].r, z=Q[i].z;
    int j = log2(r-l+1);
    ll res = gcd(st[l][j], st[r-(1<<j)+1][j]);
    if (res != z) {
      cout << "Impossible\n"; return 0;
    }
  }

  for (int i=1;i<=n;i++)
    cout << a[i] << ' ';
  cout << '\n';
}