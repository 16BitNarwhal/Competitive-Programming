#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    if (n&1) {
      cout << "0\n";
      continue;
    }
    ll ans=1;
    for (int i=1;i<=n/2;i++) {
      ans = ans*i%MOD;
    }
    ans = ans*ans%MOD;
    cout << ans << '\n';
  }
}