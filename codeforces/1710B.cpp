#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ostream& operator<<(ostream& os, const pair<ll,ll>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

pair<ll,ll> intersect(pair<ll,ll> a, pair<ll,ll> b) {
  if (a.first > b.first) swap(a,b);
  ll x1 = a.first, x2 = b.first, y1 = a.second, y2 = b.second;
  ll nx = (x1-y1+x2+y2)/2, ny = (y1-x1+x2+y2)/2;
  if (ny < y1) return {x1,y1};
  if (ny < y2) return {x2,y2};
  return {nx,ny};
}

int main() {
  ll t; cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    m*=2;
    map<ll,ll> mp;
    vector<pair<ll,ll>> rain(n);
    for (int i=0;i<n;i++) {
      ll x, p;
      cin >> x >> p;
      x *= 2; p *= 2;
      rain[i] = {x,p};
      mp[x-p]++;
      mp[x]-=2;
      mp[x+p]++;
    }
    ll a=0, d=0, prv=0;
    pair<ll,ll> key={0,-1e18};
    for (auto [x,y]: mp) {
      a += (x-prv) * d; 
      prv = x;
      if (a>m) {
        key = intersect(key,{x,a-m});
      }
      d += y;
    } 
    for (int i=0;i<n;i++) {
      if (intersect(key, rain[i]) == rain[i]) {
        cout << "1";
      } else {
        cout << "0";
      }
    }
    cout << '\n';
  }
}