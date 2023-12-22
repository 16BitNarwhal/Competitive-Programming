#include <bits/stdc++.h>
using namespace std;
int n, k, a[100001], cnt[10001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  for (int i=0;i<n;i++) {
    cin >> a[i]; 
    cnt[a[i]]++;
  }
  long long ans=0;
  for (int i=0;i<=10000;i++) {
    for (int j=i;j<=10000;j++) {
      if (__builtin_popcount(i^j) == k) {
        if (i==j)
          ans += 1LL * cnt[i] * (cnt[i]-1) / 2;
        else
          ans += 1LL * cnt[i] * cnt[j];
      }
    }
  }
  cout << ans << '\n';
}