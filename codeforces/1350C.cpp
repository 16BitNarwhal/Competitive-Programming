#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ar[100005], pre[100005], suf[100005];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a,b) * b; }
int main() {
  int n;cin>>n;
  for (int i=1;i<=n;i++) {
    cin >> ar[i];
    pre[i] = gcd(ar[i], pre[i-1]);
  }
  for (int i=n;i>=0;i--) {
    suf[i] = gcd(ar[i], suf[i+1]);
  }
  ll ans=1;
  for (int i=1;i<=n;i++) {
    int x = gcd(pre[i-1], suf[i+1]);
    ans = lcm(ans, x);
  }
  cout << ans << '\n';
}