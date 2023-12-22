#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k; 
int main() {
  cin >> n >> k;
  if (k>1e8) {
    cout << "-1\n";
    return 0;
  }
  ll b = n / (k*(k+1)/2);
  if (b==0) {
    cout << "-1\n";
    return 0;
  }
  ll r=1;
  for (ll i=1;i*i<=n;i++) {
    if (n%i!=0) continue;
    if (i<=b && i>r) r=i;
    if (n/i<=b && n/i>r) r=n/i;
  }
  for (int i=1;i<k;i++) 
    cout << r*i << ' ';
  n -= r*(k-1)*k/2;
  cout << n << '\n';
}