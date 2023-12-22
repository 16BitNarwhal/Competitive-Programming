#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
int a[MM];
bool isGood(int l, int r) {
  for (int i=l;i<=r;i++) {
    for (int j=i+1;j<=r;j++) {
      for (int k=j+1;k<=r;k++) {
        if (a[i] >= a[j] && a[j] >= a[k])
          return 0;
        if (a[i] <= a[j] && a[j] <= a[k])
          return 0;
      }
    }
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  int t;cin>>t;
  while(t--) {
    int n;cin>>n;

    for (int i=0;i<n;i++) cin >> a[i];

    int ans=0;
    for (int l=0, r=0; r<n; r++) {
      while (!isGood(l, r)) 
        l++;
      ans += r-l+1;
    }
    cout << ans << '\n';
  }
}