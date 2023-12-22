#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int t;cin>>t;
  while(t--) {
    ll n,a,b;
    cin>>n>>a>>b;
    ll req = (n+1)/2;
    ll tot = (req/a) * (b+a);
    if (req%a==0) tot -= b;
    else tot += req % a;
    cout << max(tot,n) << '\n';
  }
}