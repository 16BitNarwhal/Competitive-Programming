#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
int n, ar[101];
int main() {
  int t;cin>>t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> ar[i]; 
    }
    ll ans=0;
    for (int l=0;l<n;l++) {
      int cnt=0;
      for (int r=l;r<n;r++) {
        cnt += (ar[r]==0);
        ans += cnt + r-l+1;
      }
    }
    cout << ans << '\n';
  }
}