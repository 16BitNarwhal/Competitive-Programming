#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
#define f first
#define s second
map<pi, ll> cnt;
int gcd(int a, int b) { return (b==0?a:gcd(b, a%b)); }
pi sub(pi a, pi b) { return { a.f - b.f, a.s - b.s }; }
pi normalize(pi v) {
  int fac;
  if (min(v.f, v.s)==0) {
    fac = abs(max(v.f, v.s));
    if (fac==0) return {0,0};
  } else {
    fac = gcd(abs(v.f), abs(v.s));
  }
  return { v.f / fac, v.s / fac };
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    cnt.clear();
    int n;cin>>n;
    for (int i=0;i<n;i++) {
      pi a, b;
      cin >> a.f >> a.s >> b.f >> b.s;
      pi v = sub(a, b);
      cnt[normalize(v)]++;
    }
    ll ans=0;
    for (auto i : cnt) {
      pi v = i.f;
      ans += cnt[ {v.f, v.s} ] * cnt[ {-v.f, -v.s} ];
    }
    cout << ans / 2 << '\n';
  }
}