#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5001;
int n;
ll a[MM], b[MM], pre[MM];
int main() {
  cin >> n;
  for (int i=0;i<n;i++) cin>>a[i];
  for (int i=0;i<n;i++) cin>>b[i];
  for (int i=0;i<n;i++) 
    pre[i] = (i>0?pre[i-1]:0) + (a[i]*b[i]);
  ll ans=pre[n-1];
  for (int c=0;c<n;c++) {
    ll cur = a[c] * b[c];
    for (int l=c-1, r=c+1; l>=0 && r<n; l--, r++) {
      cur += a[l] * b[r];
      cur += a[r] * b[l];
      ans = max(ans, cur + (l>0?pre[l-1]:0) + (pre[n-1] - pre[r]));
    }
    cur = 0;
    for (int l=c, r=c+1; l>=0 && r<n; l--, r++) {
      cur += a[l] * b[r];
      cur += a[r] * b[l];
      ans = max(ans, cur + (l>0?pre[l-1]:0) + (pre[n-1] - pre[r]));
    }
  }
  cout << ans << '\n';
}