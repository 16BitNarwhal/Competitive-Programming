#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n,q,ar[MM];
int main() {
  cin >>n>>q;
  for (int i=0;i<n;i++)cin>>ar[i];
  sort(ar, ar+n);
  while (q--) {
    int x;cin>>x;
    int l=0,r=n-1;
    bool ans=0;
    while (l<=r) {
      int m = l + (r-l)/2;
      if (ar[m]==x) {
        ans=1;
        break;
      } else if (ar[m]<x) {
        l=m+1;
      } else {
        r=m-1;
      }
    }
    cout << (ans ? "YES\n" : "NO\n");
  }
}