#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
bool isfib[MM], isprime[MM];
int main() {
  // sieve
  memset(isprime, true, sizeof(isprime));
  for (int i = 2; i < MM; i++) {
    if (isprime[i]) {
      for (int j = i+i; j < MM; j += i) {
        isprime[j] = false;
      }
    }
  }
  // fib
  int a = 1, b = 1;
  while (a < MM) {
    isfib[a] = true;
    int c = a+b;
    a = b;
    b = c;
  }
  int t,n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (!isprime[n] && isfib[n]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}