// plsss
#include <bits/stdc++.h>
using namespace std;
typedef long double ll;
ll h, c, t;
ll fun(ll k) {
  return ((k+1)*h + k*c)/(2*k+1);
}
void solve() {
  cin >> h >> c >> t; 
  if ((h+c)/2 >= t) {
    cout << 2 << '\n';
    return;
  }
  int res=0, l=0, r=1e6;
  while (l<=r) {
    int m = (l+r)/2;
    if(fun(m)>t) res=m, l=m+1;
    else r=m-1;
  } 
  ll a = abs(t-fun(res));
  ll b = abs(t-(h+c)/2);
  ll c = abs(t-fun(res+1));
  if (a <= b && a <= c) {
    cout << 2*res + 1 << '\n';
  } else if (b <= c) {
    cout << 2*res + 2 << '\n';
  } else {
    cout << 2*res + 3 << '\n';
  }
}
int main() {
  int t;cin>>t;
  while(t--)solve();
}