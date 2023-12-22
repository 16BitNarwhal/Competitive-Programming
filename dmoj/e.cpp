#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 4e8;
bool v[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  memset(v, 1, sizeof(v));
  ll n;cin>>n;
  for (int k=1;k<=18;k++) {
    if (pow(3,k) >= n) break;
    ll x = pow(3,k);
    ll y = 2*pow(3,k);
    for (int i=x+2;i<y;i++) {
      v[i] = 0;
    }
  }
  for (int i=0;i<=n;i++) {
    if (v[i]) cout << i << '\n';
  }
}