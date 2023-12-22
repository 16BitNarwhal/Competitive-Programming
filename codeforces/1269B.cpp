#include <bits/stdc++.h>
using namespace std;
const int MM = 2002;
int n, m, a[MM], b[MM], c[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    cin >> a[i];  
  }
  for (int i=0;i<n;i++) {
    cin >> b[i];  
  } 
  sort(b, b+n);
  int ans=1e9;
  for (int i=0;i<n;i++) {
    int x = (b[i] - a[0] + m) % m;
    for (int j=0;j<n;j++) {
      c[j] = (a[j] + x) % m;
    }
    sort(c, c+n);
    bool ok=1;
    for (int j=0;j<n;j++) { 
      if (b[j] != c[j]) {
        ok=0; break;
      }
    }
    if (ok) ans = min(ans, x);  
  }
  cout << ans << '\n';
}