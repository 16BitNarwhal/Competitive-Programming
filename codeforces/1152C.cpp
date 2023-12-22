#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int main() {
  ll a, b;
  cin>>a>>b;
  if (a>b) swap(a,b);
  ll n = b-a;
  ll ans=0, mn = 1e18;
  for (ll i=1;i*i<=n;i++) {
    if (n%i==0) {
      ll k = (2*a*i -a) % i;
      ll x = lcm(a+k, b+k);
      if (x<mn) {
        mn = x; 
        ans = k;
      }

      k = (2*a*(n/i) -a) % (n/i);
      x = lcm(a+k, b+k);
      if (x<mn) {
        mn=x;
        ans=k;
      }
    }
  }
  cout << ans << '\n';
}