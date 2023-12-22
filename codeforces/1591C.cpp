#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
typedef long long ll;
ll ar[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    int n,k;cin>>n>>k;
    for (int i=0;i<n;i++) cin>>ar[i];
    sort(ar,ar+n);
    ll ans=0;
    int cnt=0;
    for (int i=0;i<n;i++) {
      if (ar[i]>=0) break;
      if (cnt%k==0) ans += abs(ar[i]) + abs(ar[i]);
      cnt++;
    }
    cnt=0;
    for (int i=n-1;i>=0;i--) {
      if (ar[i]<=0) break;
      if (cnt%k==0) ans += abs(ar[i]) + abs(ar[i]);
      cnt++;
    }
    ans -= max(abs(ar[0]), abs(ar[n-1]));
    cout << ans << '\n';
  }
}