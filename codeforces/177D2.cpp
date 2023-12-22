#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
ll a[MM], add[MM];
int main() {
  int n, m, mod;
  cin>>n>>m>>mod;
  for (int i=1;i<=n;i++) {
    cin >> a[i];
  }
  for (int i=1;i<=m;i++) {
    int x;cin>>x;
    add[i] += x;
    add[i+n-m+1] -= x;
  }
  for (int i=1;i<=n;i++) {
    add[i] += add[i-1];
    cout << (a[i] + add[i]) % mod << ' ';
  }
}