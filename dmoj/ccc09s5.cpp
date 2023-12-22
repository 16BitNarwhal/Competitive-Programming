#include <bits/stdc++.h>
using namespace std;
int ar[1005][30005];
int main() {
  int m, n, k;
  cin >> m >> n >> k;
  for (int i=0;i<k;i++) {
    int x, y, r, b;
    cin >> x >> y >> r >> b;
    int lo = max(x-r, 1), hi = min(x+r, n);
    for (int j=lo;j<=hi;j++) {
      int h = sqrt(r*r - (j-x)*(j-x));
      ar[j][max(y-h, 1)]+=b;
      ar[j][min(y+h, m)+1]-=b;
    }
  }
  int mx=-1, cnt=0;
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      ar[i][j] += ar[i][j-1]; 
      if (ar[i][j] > mx) {
        mx = ar[i][j];
        cnt = 1;
      } else if (ar[i][j]==mx) {
        cnt++;
      }
    } 
  }
  cout << mx << '\n' << cnt << '\n';
}