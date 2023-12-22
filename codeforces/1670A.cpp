#include <bits/stdc++.h>
using namespace std; 
const int MM = 1e5+2;
int ar[MM];
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    for (int i=0;i<n;i++) cin >> ar[i];
    int l=0, r=n-1;
    while (l<r) {
      while (ar[r]>0) r--;
      while (ar[l]<0) l++;
      if (l<r && ar[l]>ar[r]) {
        ar[l] *= -1;
        ar[r] *= -1;
      }
      r--;
      l++;
    }
    bool ans = true;
    for (int i=1;i<n;i++) { 
      if (ar[i-1]>ar[i]) {
        ans = false;
      }
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }
}