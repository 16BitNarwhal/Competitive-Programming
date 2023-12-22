#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int t; cin>>t;
  while (t--) {
    ll n, x;
    cin>>n>>x;
    ll sum=0;
    for (int i=0;i<n;i++) {
      ll v;cin>>v;
      if (v <= x) sum += v;
    }
    ll ans = x*(x+1)/2;
    ans -= sum * 2;
    cout << ans << '\n';
  }
}