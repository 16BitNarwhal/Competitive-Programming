#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MM = 2e5;
ll a[MM];

bool is_valid(ll i, ll j, ll k) {
  return (i<j+k)&&(j<i+k)&&(k<i+j);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ll n;cin>>n;
  for (ll i=0;i<n;i++) cin >> a[i];

  sort(a, a+n, greater<ll>());

  vector<pair<ll,ll>> sums;
  for (ll i=0;i<n-2;i++) {
    if (is_valid(a[i],a[i+1],a[i+2])) {
      sums.push_back({i,a[i] + a[i+1] + a[i+2]});
    }
  }

  // check all "valid" pairs in sums
  ll ans=0;
  for (ll i=0;i<(ll)sums.size();i++) { 
    for (ll j=i+1;j<min(i+6, (ll)sums.size());j++) {
      if (sums[j].first - sums[i].first >= 3) {
        ans = max(ans, sums[i].second + sums[j].second);
      }
    }
  }

  ll combinations[][3] = {
    {0,1,2},
    {0,1,3},
    {0,1,4},
    {0,1,5},
    {0,2,3},
    {0,2,4},
    {0,2,5},
    {0,3,4},
    {0,3,5},
    {0,4,5}
  };

  for (ll i=0;i<n-5;i++) {
    vector<ll> v;
    for (ll j=i;j<i+6;j++) v.push_back(a[j]);

    // check if any of v consists of 2 valid triangles
    for (auto c : combinations) {
      vector<ll> o;
      for (ll x=0;x<6;x++) {
        if (x!=c[0] && x!=c[1] && x!=c[2]) o.push_back(x);
      }
      
      if (is_valid(v[c[0]],v[c[1]],v[c[2]]) && is_valid(v[o[0]],v[o[1]],v[o[2]])) {
        ans = max(ans, v[c[0]] + v[c[1]] + v[c[2]] + v[o[0]] + v[o[1]] + v[o[2]]);
        break;
      }
    }
  }
  cout << ans << '\n';
}