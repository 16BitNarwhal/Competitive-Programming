#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
struct stack {
  vector<ll> s, sgcd={0};
  void push(ll x) {
    s.push_back(x);
    sgcd.push_back(::gcd(x, sgcd.back()));
  }
  ll pop() {
    ll ret = s.back();
    s.pop_back();
    sgcd.pop_back();
    return ret;
  }
  bool empty() {
    return s.empty();
  }
  ll gcd() {
    return sgcd.back();
  }
};
ll n, ar[100005];
::stack s1, s2;
bool good() { 
  return gcd(s1.gcd(), s2.gcd())==1;
}
int main() {
  cin >> n;
  for (int i=0;i<n;i++) 
    cin >> ar[i]; 
  int l=0, ans=1e9;
  for (int r=0;r<n;r++) {
    s2.push(ar[r]);
    while (good()) {
      if (s1.empty()) {
        while (!s2.empty())
          s1.push(s2.pop());
      }
      s1.pop();
      ans = min(ans, r-l+1);
      l++;
    }
  }
  cout << (ans==1e9?-1:ans) << '\n';
}