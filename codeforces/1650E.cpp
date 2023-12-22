#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int n, d, ar[MM];
int calc(int idx) {
  int mx = d - ar[n] - 1;
  if (idx==n) mx = d - ar[n-1] - 1;
  for (int i=0;i<=n;i++) {
    int l = ar[i], r = (i+1 == idx) ? ar[i+2] : ar[i+1];
    mx = max(mx, (r-l)/2 - 1);
  }
  int prv=0;
  int mn=2e9;
  for (int i=1;i<=n;i++) {
    if (i==idx) continue;
    mn = min(mn, ar[i] - prv - 1);
    prv = ar[i];
  } 
  return min(mx, mn);
}
int main() {
  int t;cin>>t;
  while (t--) {
    cin >> n >> d;
    for (int i=1;i<=n;i++) {
      cin >> ar[i];
    }
    ar[n+1] = d;
    int mn=2e9, idx=0;
    for (int i=1;i<=n;i++) {
      if (ar[i]-ar[i-1] < mn) {
        mn = ar[i]-ar[i-1];
        idx = i-1;
      }
    } 
    if (idx==0) idx++; 
    cout << max(calc(idx), calc(idx+1)) << '\n';
    
  }
}