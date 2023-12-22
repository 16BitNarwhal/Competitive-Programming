#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
  ll n, a, b;
  cin >> n >> a >> b;
  if (a==1) {
    if ((n-1)%b == 0) cout << "yes\n";
    else cout << "no\n";
    return;
  }
  ll x=1;
  while (x <= n) {
    if ((n-x) % b == 0) {
      cout << "yes\n";
      return;
    }
    x *= a;
  }
  cout << "no\n";
}
int main() {
  int t; cin>>t;
  while(t--) solve();
}
