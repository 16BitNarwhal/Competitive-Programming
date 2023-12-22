#include <bits/stdc++.h>
using namespace std;
const int MM = 5e4+5;
int ar[MM];
int main() {
  int t;cin>>t;
  while (t--) {
    int n; cin>>n;
    for (int i=0;i<n;i++) cin>>ar[i];
    int x; cin>>x;
    for (int i=0;i<n;i++) ar[i] -= x;
    int l = 0;
    int sum = ar[0];
    int cnt=0;
    for (int r=1;r<n;r++) {
      sum += ar[r];
      while (sum >= 0 && r-l+1 > 2) {
        sum -= ar[l];
        l++;
      }
      if (sum < 0) {
        r++;
        l=r;
        sum = ar[l];
        cnt++;
      }
    }
    cout << n-cnt << '\n';
  }
}