#include <bits/stdc++.h>
using namespace std;

int n, k, ar[1010];

bool check(int x) {
  int cnt=0;
  int last_covered=-1e6;
  for (int i=0;i<n;i++) {
    if (ar[i] > last_covered) {
      cnt++;
      last_covered = ar[i] + 2*x;
    }
  }
  return cnt <= k;
}

int main() {
  cin >> n;
  for (int i=0;i<n;i++) cin >> ar[i];
  sort(ar, ar+n);
  cin >> k;

  int ans=1e6;
  for (int shift=0;shift<n;shift++) {
    int tmp = ar[1];
    for (int i=0;i<n;i++) {
      ar[i] -= tmp;
      if (ar[i] < 0) ar[i] += 1e6;
    }
    sort(ar, ar+n);

    int lo = 0, hi = 1e6, res=1e6;
    while (lo <= hi) {
      int mid = (lo+hi)/2;
      if (check(mid)) {
        res = mid;
        hi = mid-1;
      } else lo = mid+1;
    }
    ans = min(ans, lo);
  }
  cout << ans << '\n';
}