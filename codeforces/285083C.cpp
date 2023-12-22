#include <bits/stdc++.h>  
using namespace std;
const int MM = 1e4+2;
int n,k,ar[MM];
bool check(int x) {
  int cnt=1, prev=ar[0];
  for (int i=1;i<n;i++) {
    if (ar[i] - prev >= x) {
      cnt++;
      prev = ar[i];
    }
  }
  return cnt >= k;
}
int main() {
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> ar[i];
  int l=0,r=1e9,ans=-1;
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