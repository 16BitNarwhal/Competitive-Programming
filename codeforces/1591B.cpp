#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int ar[MM], n, mx, ans=0;
int main() {
  int t;cin>>t;
  while(t--) {
    cin>>n;
    for (int i=1;i<=n;i++) {
      cin>>ar[i];
    }
    ans=0;
    mx=0;
    for (int i=n;i>0;i--) {
      if (ar[i]>mx) {
        mx=ar[i];
        ans++;
      }
    }
    cout << ans-1 << '\n';
  }
}