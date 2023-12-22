#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
struct op {
  ll l,r,d;
} ops[MM];
ll ar[MM], cum[MM], qry[MM];
int main() {
  int n,m,k;
  cin>>n>>m>>k;
  for (int i=1;i<=n;i++) 
    cin >> ar[i];
  for (int i=1;i<=m;i++) { 
    cin >> ops[i].l >> ops[i].r >> ops[i].d;
  }
  for (int i=0;i<k;i++) {
    int l,r;cin>>l>>r;
    qry[l]++;
    qry[r+1]--;
  }
  for (int i=1;i<=m;i++) {
    qry[i] += qry[i-1];
    ll d = ops[i].d * qry[i];
    int l=ops[i].l, r=ops[i].r;
    cum[l] += d;
    cum[r+1] -= d;
  }
  for (int i=1;i<=n;i++) {
    cum[i] += cum[i-1];
    cout << ar[i] + cum[i] << ' ';
  }
  cout << '\n';
}