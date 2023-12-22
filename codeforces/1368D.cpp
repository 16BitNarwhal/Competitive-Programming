#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
int n, a[MM], cnt[20];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin>>a[i];
  ll ans=0;
  for (int i=0;i<n;i++) {
    for (int k=0;k<20;k++) 
      if (a[i] & (1<<k)) cnt[k]++;
  }
  for (int i=0;i<n;i++) {
    ll x=0;
    for (int k=0;k<20;k++) {
      if (cnt[k]) {
        x |= (1<<k);
        cnt[k]--;
      }
    }
    ans += x*x;
  }
  cout << ans << '\n';
}