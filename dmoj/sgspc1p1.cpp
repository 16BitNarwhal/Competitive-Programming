#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005];
int main() {
  int n;cin>>n;
  for (int i=0;i<n;i++) cin >> a[i];
  ll tot=0;
  for (int i=0;i<n;i++) tot += (ll)(i+1)*(n-i);
  int ans=0;
  for (int j=0;j<31;j++) {
    ll cnt=0;
    for (int i=0;i<n;i++) {
      if (a[i]&(1<<j)) {
        cnt += (ll)(i+1)*(n-i);
      }
    } 
    if (cnt > tot/2) {
      ans |= (1<<j);
    }
  }
  cout << ans << '\n';
}
