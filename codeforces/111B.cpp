#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int ar[MM];
vector<ll> getDiv(ll n) {
  vector<ll> ret;
  for (int i=1;i*i<=n;i++) {
    if (n%i==0) {
      ret.push_back(i);
      if (i*i!=n) ret.push_back(n/i);
    }
  }
  return ret;
}
int main() {
  memset(ar, -1, sizeof ar);
  int n;cin>>n;
  for (int i=0;i<n;i++) {
    int x,y;
    cin>>x>>y;
    vector<ll> div = getDiv(x);
    int ret=0;
    for (ll d : div) {
      if (ar[d] < i-y)
        ret++;
      ar[d] = i;
    }
    cout << ret << '\n';
  }
}