#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
int n, k, ar[MM];
bool check(int x) {
  int sum=0;
  for (int i=n/2;i<n;i++) {
    if (ar[i]<x) {
      sum += x-ar[i];
      if (sum>k) return false;
    } else break;
  }
  return true;
}
int main() {
  cin >> n >> k;
  for (int i=0;i<n;i++) cin>>ar[i];
  sort(ar, ar+n);
  int l=0,r=2e9,ans=0;
  while (l<=r) {
    int m = l + (r-l)/2;
    if (check(m)) {
      ans=m, l=m+1;
    } else {
      r=m-1;
    }
  }
  cout << ans << '\n';
}