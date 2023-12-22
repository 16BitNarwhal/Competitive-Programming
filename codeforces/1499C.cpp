#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int t;cin>>t;
  while(t--) {
    int n;cin>>n;
    vector<int> mn(2, 1e9), cnt(2);
    ll sum=0, ans=1e18;
    for (int i=0,x;i<n;i++) {
      cin >> x;
      mn[i%2] = min(mn[i%2], x);
      cnt[i%2]++;
      sum += x;
      if (i) {
        ans = min(ans, sum + (1LL*(n-cnt[0])*mn[0]) + (1LL*(n-cnt[1])*mn[1]));
      }
    }
    cout << ans << '\n';
  }
  
}