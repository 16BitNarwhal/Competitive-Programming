#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
int n, k, ar[MM];
bool check(int x) {
  int sum=0;
  for (int i=0;i<n;i++) {
    sum += max(0, ar[i]-(i/x));
    if (sum >= k) return true;
  }
  return false;
}
int main() {
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> ar[i];
  sort(ar, ar+n, greater<int>()); 
  int l=1, r=n, ans=-1;
  while (l<=r) {
    int m = l + (r-l)/2; 
    if (check(m)) {
      ans = m;
      r = m-1;
    } else l = m+1;
  }
  cout << ans << '\n';
}