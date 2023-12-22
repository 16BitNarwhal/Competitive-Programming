#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200002];
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    ll nsum=0, psum=0;
    for (int i=0;i<n;i++) {
      cin >> a[i];
      if (i && a[i]-a[i-1]>0) {
        psum += a[i]-a[i-1];
      } else if (i && a[i]-a[i-1]<0) {
        nsum += a[i-1]-a[i];
      }
    }
    ll ans = nsum + psum + abs(a[0] - nsum);
    cout << ans << '\n';
  }
}