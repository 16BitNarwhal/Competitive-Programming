#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
typedef pair<int,int> pi;
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    vector<pi> v(n);
    vector<int> L, R;
    for (auto &[l, r] : v) {
      cin>>l>>r;
      L.push_back(l);
      R.push_back(r);
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    int ans=1e9;
    for (auto [l,r] : v) {
      int ll = lower_bound(R.begin(), R.end(), l) - R.begin();
      int rr = upper_bound(L.begin(), L.end(), r) - L.begin();
      ans = min(ans, ll + n-rr);
    }
    cout << ans << '\n';
  }
}