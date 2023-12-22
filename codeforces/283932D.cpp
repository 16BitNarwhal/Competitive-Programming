#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, T[1001], Z[1001], Y[1001], res[1001], cur[1001];
bool check(int t) {
  int sum=0;
  for (int i=0;i<n;i++) {
    int a = t / (T[i] * Z[i] + Y[i]);
    int b = t % (T[i] * Z[i] + Y[i]);
    cur[i] = a*Z[i] + min(b/T[i], Z[i]);
    sum += cur[i];
    if (sum > m) {
      cur[i] -= sum - m;
      sum = m;
    }
  }
  return (sum == m);
}
int main() {
  cin >> m >> n;
  for (int i=0;i<n;i++) {
    cin >> T[i] >> Z[i] >> Y[i];
  }
  int l=0,r=1,ans=-1;
  while (!check(r)) r*=2;
  while (l<=r) {
    int m = l + (r-l)/2;
    if (check(m)) {
      for (int i=0;i<n;i++) res[i]=cur[i];
      ans = m; r = m-1;
    } else {
      l = m+1;
    }
  }
  cout << ans << '\n';
  for (int i=0;i<n;i++) cout << res[i] << ' ';
}