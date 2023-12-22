#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2, mod = 998244353;
int add(ll a, ll b) { return (a+b+mod)%mod; }
int mul(ll a, ll b) { return (a*b)%mod; }
int f(int x, int l, bool flag) {
  // flag differs 1010 and 101
  int res=0, ten=(flag?10:1), sz = log10(x)+1;
  for (int i=0;i<sz; i++) {
    res = add(res, mul(x % 10, ten));
    x /= 10;
    ten = mul(ten, 10);
    if (i + flag < l) ten = mul(ten, 10);
  }
  return res;
}
int ar[MM], cnt[11];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  for (int i=0;i<n;i++) {
    cin >> ar[i];
    cnt[(int)log10(ar[i])+1]++;
  }
  int ans=0;
  for (int i=0;i<n;i++) {
    for (int l=1;l<=10;l++) {
      int sum = f(ar[i], l, true);
      ans = add(ans, mul(sum, cnt[l]));

      sum = f(ar[i], l, false);
      ans = add(ans, mul(sum, cnt[l]));      
    }
  }
  cout << ans << '\n';
}