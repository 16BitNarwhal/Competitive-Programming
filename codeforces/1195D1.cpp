#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2, mod = 998244353;
int add(ll a, ll b) { return (a+b+mod)%mod; }
int mul(ll a, ll b) { return (a*b)%mod; } 
int ten[30];
ll f(int x) {
  int pos=0;
  ll res=0;
  while (x>0) {
    int cur = x%10;
    x /= 10;
    res = add(res, mul(cur, ten[2*pos]));
    res = add(res, mul(cur, ten[2*pos+1]));
    pos++;
  }
  return res;
}
int main() {
  ten[0] = 1;
  for (int i=1;i<30;i++) ten[i] = mul(ten[i-1], 10);

  int n; cin >> n;
  int ans=0; 
  for (int i=0;i<n;i++) {
    int x;cin>>x;
    ans = add(ans, mul(n, f(x)));
  }
  cout << ans << '\n';
}