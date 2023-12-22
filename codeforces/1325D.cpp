#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll u, v;
  cin >> u >> v;
  if (u>v || v-u&1) {
    cout << "-1\n";
  } else if (u==v) {
    if (u==0) cout<<"0\n";
    else cout << "1\n" << u << '\n';
  } else {
    ll x = (v-u)/2;
    // if no common bits in both u and x, then can treat u+x as 1 
    if ((u&x)==0) cout << "2\n" << u+x << ' ' << x << '\n';
    else cout << "3\n" << u << ' ' << x << ' ' << x << '\n';
  }
}