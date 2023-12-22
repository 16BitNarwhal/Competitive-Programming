#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 250005;
ll n, m, fac[MM];
int main() {
  cin >> n >> m;
  fac[0]=1;
  for (int i=1;i<=n;i++) fac[i] = fac[i-1] * i % m;
  ll res=0;
  // // O(n*2)
  // for (int l=1;l<=n;l++) {
  //   for (int r=l;r<=n;r++) {
  //     res = (res + fac[n-(r-l)]*fac[r-l+1]) % m;
  //   }
  // }

  // O(n)
  for (int i=1;i<=n;i++) {
    res = (res + (fac[n-i+1]*fac[i]%m)*(n-i+1)%m) % m;
  }
  cout << res << '\n';
}