#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int pre[MM], suf[MM], ar[MM];
int main() {
  int n;cin>>n;
  for (int i=0;i<n;i++) {
    cin >> ar[i];
    pre[i] = suf[i] = ar[i];
    if (i>=2) pre[i] += pre[i-2];
  }
  for (int i=n-3;i>=0;i--) {
    suf[i] += suf[i+2];
  }
  int ans=0;
  for (int i=0;i<n;i++) {
    int a = (i?pre[i-1]:0) + (i<n-2?suf[i+2]:0);
    int b = (i>1?pre[i-2]:0) + (i<n-1?suf[i+1]:0);
    ans += a==b;
  }
  cout << ans << '\n';
}