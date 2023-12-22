#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5005;
int ar[MM], pre[MM][MM], suf[MM][MM];
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin >> ar[i];
    for (int i=1;i<=n;i++) { 
      pre[i][0] = 0;
      for (int j=1;j<=n;j++) {
        pre[i][j] = pre[i][j-1] + (i > ar[j]);
      }
      suf[i][n+1] = 0;
      for (int j=n;j>=1;j--) {
        suf[i][j] = suf[i][j+1] + (i > ar[j]);
      }
    }
    ll ans=0;
    for (int i=2;i<=n;i++) {
      int b = ar[i];
      for (int j=i+1;j<=n;j++) {
        int c = ar[j];
        int num_a = pre[c][i-1];
        int num_b = suf[b][j+1];
        ans += num_a * num_b;
      }
    }
    cout << ans << '\n';
  }
}