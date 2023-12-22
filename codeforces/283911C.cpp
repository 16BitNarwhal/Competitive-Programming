#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n,q,ar[MM];
int main() {
  cin >>n>>q;
  for (int i=0;i<n;i++)cin>>ar[i];
  while(q--) {
    int x;cin>>x;
    int l=0,r=n;
    while (l<r) {
      int m = l + (r-l)/2;
      if (ar[m] >= x) {
        r=m;
      } else {
        l=m+1;
      }
    }
    cout << r+1 << '\n';
  }
}