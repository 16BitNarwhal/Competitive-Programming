#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll n, m, k;
  cin>>n;
  if (n<=2) {
    cout << "-1\n";
    return 0;
  }
  if (n&1) {
    k = (n*n + 1)/2;
    m = k - 1;
  } else {
    k = (n*n)/4 + 1;
    m = k - 2;
  }
  cout << m << ' ' << k << '\n';
}