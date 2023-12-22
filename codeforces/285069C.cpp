#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int MM = 1e5+2;
pair<ld,ld> ar[MM];
int n, k;
ld ans, a[MM];
bool check(ld x) {
  for (int i=0;i<n;i++) 
    a[i] = ar[i].first - (x * ar[i].second);
  sort(a, a+n, greater<ld>());
  ld sum=0;
  for (int i=0;i<k;i++) 
    sum += a[i];
  return sum >= 0;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  for (int i=0;i<n;i++)
    cin >> ar[i].first >> ar[i].second;
  ld l=0,r=1;
  while (check(r)) r*=2;
  while (r-l > 1e-7) {
    ld m = l + (r-l)/2;
    if (check(m)) {
      ans=m;
      l=m;
    } else {
      r=m;
    }
  }
  cout << fixed << setprecision(8) << ans << '\n';
}
/*

sum(ai) / sum(bi) >= x
sum(ai) >= x sum(bi)
sum(ai) - x sum(bi) >= 0
sum(a - x*b) >= 0

sort(a - x*b), take the first k

*/