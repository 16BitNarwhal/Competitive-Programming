#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
ll ar[MM], diff1[MM], diff2[MM];
struct op {ll l, r, x;} ops[MM];
int main() {
  int n, m, k;
  cin>>n>>m>>k;
  for (int i=1;i<=n;i++) {
    cin >> ar[i];
    diff1[i] = ar[i] - ar[i-1];
  }
  for (int i=1;i<=m;i++) {
    cin >> ops[i].l >> ops[i].r >> ops[i].x;
  }
  for (int i=0;i<k;i++) {
    int l,r;cin>>l>>r;
    diff2[l]++;
    diff2[r+1]--;
  }
  for (int i=1;i<=m;i++) {
    diff2[i] += diff2[i-1];
    ll l=ops[i].l, r=ops[i].r, x=ops[i].x;
    diff1[l] += x * diff2[i];
    diff1[r+1] -= x * diff2[i];
  }
  for (int i=1;i<=n;i++) {
    diff1[i] += diff1[i-1];
    cout << diff1[i] << ' ';
  }
}