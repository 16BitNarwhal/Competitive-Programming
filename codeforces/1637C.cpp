#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
typedef long long ll;
int n, ar[MM]; 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    cin>>n;
    ll ans=0;
    bool flag=false;
    for (int i=0;i<n;i++) {
      cin>>ar[i];
      if (i>0 && i<n-1) {
        if (n >= 4) flag |= (ar[i]>=2);
        else flag |= (ar[i]%2==0);
        ans += (ar[i]+1)/2;
      }
    }
    if (flag) cout << ans << '\n';
    else cout << "-1\n";
  }
}