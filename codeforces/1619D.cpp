#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> ar[100005];
bool check(int x) {
  for (int j=0;j<n;j++) {
    int mx=0;
    for (int i=0;i<m;i++) 
      mx = max(mx, ar[i][j]);
    if (mx < x) return false;
  }
  for (int i=0;i<m;i++) {
    int mx1=0, mx2=0;
    for (int j=0;j<n;j++) {
      if (ar[i][j] > mx1) {
        mx2 = mx1;
        mx1 = ar[i][j];
      } else if (ar[i][j] > mx2) {
        mx2 = ar[i][j];
      }
    }
    if (mx2 >= x) return true;
  }
  return false;
}
int main() {
  int t;cin>>t;
  while (t--) {
    cin >> m >> n;
    int mx=0;
    for (int i=0;i<m;i++) {
      ar[i] = vector<int>(n);
      for (auto &x:ar[i]) {
        cin >> x; 
      mx = max(mx, x);
      }
    } 
    int l=0, r=1e9, ans=-1;
    while (l<=r) {
      int m = l + (r-l)/2;
      if (check(m)) {
        ans=m;
        l=m+1;
      } else {
        r=m-1;
      }
    }
    cout << ans << '\n';
  }
}