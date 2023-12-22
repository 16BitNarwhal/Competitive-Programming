#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n,q,ar[MM];
int main() {
  cin >>n;
  for (int i=0;i<n;i++)cin>>ar[i];
  sort(ar,ar+n);
  cin>>q;
  while (q--) {
    int L,R;cin>>L>>R;
    int l=0,r=n;
    while (l<r) {
      int m = l + (r-l)/2;
      if (ar[m] >= L) {
        r=m;
      } else {
        l=m+1;
      }
    }
    int ans=-l; 
    l=-1,r=n-1;
    while (l<r) {
      int m = l + (r-l+1)/2;
      if (ar[m] <= R) {
        l=m;
      } else {
        r=m-1;
      }
    }
    ans += r+1;
    cout << ans << ' ';
  }
}