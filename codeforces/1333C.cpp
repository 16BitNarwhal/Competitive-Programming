#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
ll n, p[MM], ans=0;
int main() {
  cin >> n;
  for (int i=1, x;i<=n;i++) {
    cin >> x; 
    p[i] = p[i-1] + x; 
  }
  int l=0, r=0;
  set<ll> s = {0};
  for (;l<n;l++) {
    for (;r<n && !s.count(p[r+1]);r++)
      s.insert(p[r+1]);
    ans += r-l;
    s.erase(p[l]);
  }
  cout << ans << '\n';
}