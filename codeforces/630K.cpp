#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int main() {
  ll n;cin>>n;
  ll m=1;
  for (int i=2;i<=10;i++) m=lcm(m,i);
  ll x = n / m;
  ll y = n % m;
  ll a=0,b=0;
  for (int i=1;i<=m;i++) {
    if (gcd(i,m)==1) {
      if (i<=y) a++;
      b++;
    }
  } 
  cout << a + (b*x) << '\n';
}