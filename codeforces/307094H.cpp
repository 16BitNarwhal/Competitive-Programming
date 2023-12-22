#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int n, m, s, A, B, a[MM], b[MM];
int main() {
  cin >> n >> m >> s >> A >> B;
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<m;i++) cin >> b[i];
  sort(a, a+n, greater<int>());
  sort(b, b+m, greater<int>());
  ll w=0, c=0;
  int i=0;
  while (i<n && w + A <= s) {
    w += A;
    c += a[i++];
  }
  ll ans = c;
  for (int j=0;j<m;j++) {
    w += B;
    c += b[j];
    while (i-1>=0 && w > s) { 
      w -= A;
      c -= a[--i];
    }
    if (w<=s) ans = max(ans, c); 
  } 
  cout << ans << '\n';
}