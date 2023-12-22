#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct stack {
  vector<ll> s, smin = {LLONG_MAX}, smax = {LLONG_MIN};
  void push(ll x) {
    s.push_back(x); 
    smin.push_back(::min(x, smin.back()));
    smax.push_back(::max(x, smax.back())); 
  } 
  ll pop() {
    ll ret = s.back();
    s.pop_back();
    smin.pop_back();
    smax.pop_back();
    return ret;
  } 
  bool empty() {
    return s.empty();
  } 
  ll min() { 
    return smin.back();
  } 
  ll max() { 
    return smax.back();
  }
};
ll n, k;
::stack s1, s2;
void add(ll x) {
  s2.push(x);
}
void remove() {
  if (s1.empty()) {
    while (!s2.empty())
      s1.push(s2.pop());
  }
  s1.pop();
}
bool good() {
  ll mn = min(s1.min(), s2.min());
  ll mx = max(s1.max(), s2.max());
  return mx - mn <= k;
}
int main() {
  cin >> n >> k;
  ll ans=0;
  int l=0;
  for (int r=0;r<n;r++) {
    ll x;cin>>x;
    add(x); 
    while (!good()) {
      remove();
      l++;
    }
    ans += r-l+1;
  }
  cout << ans << '\n';
}