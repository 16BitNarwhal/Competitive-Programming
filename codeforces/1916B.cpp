#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
  return a*b/gcd(a,b);
}

const int MM = 1e5+10;
vector<ll> primes;
bool isPrime[MM];
void sieve() {
  memset(isPrime, 1, sizeof isPrime);
  for (ll i=2;i<=MM;i++) {
    if (isPrime[i]) {
      primes.push_back(i);
      for (ll j=i*i;j<=MM;j+=i) {
        isPrime[j]=0;
      }
    }
  }
}

int main() {
  sieve(); 

  int t;cin>>t;
  while (t--) {
    ll a, b;
    cin >> a >> b;
    ll res = lcm(a,b);
    if (res == b) {
      ll p = 2;
      for (ll i : primes) {
        if (res % i == 0) {
          p = i;
          break;
        }
      }
      cout << res * p << endl;
    } else {
      cout << res << endl;
    }

  }
}