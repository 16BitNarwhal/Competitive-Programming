#include <bits/stdc++.h>
using namespace std;
int n, k, a[51], pow2[20];
int main() {
  pow2[0] = 1;
  for (int i=1;i<20;i++) pow2[i] = pow2[i-1]*2;
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> a[i];
  sort(a, a+n);
  int ans=1e9;
  for (int i=0;i<n;i++) {
    for (int p=0;p<20;p++) {
      int cnt=0, target= a[i]/pow2[p];
      int cur=0;
      for (int j=0;j<n;j++) {
        int x=0, val=a[j];
        while (val>target) {
          val/=2; x++;
        }
        if (val==target) {
          cur += x;
          cnt++;
        }
        if (cnt >= k) break;
      } 
      if (cnt >= k) ans = min(ans, cur);
    }
  } 
  cout << ans << '\n';
}