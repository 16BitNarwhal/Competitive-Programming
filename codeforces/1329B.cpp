#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    ll d, m; cin >> d >> m;
    ll res=1;
    for (int k=0;k<30;k++) {
      ll nxt = min((1LL<<(k+1))-1, d);
      ll cur = 1<<k;
      if (nxt<cur) break;
      res = (res*(nxt-cur+1 +1))%m;
    }
    cout << (res+m-1)%m << '\n';
  }
}