#include <bits/stdc++.h>
using namespace std;
const int MM = 3003;
int pfx[2][MM][MM];
int main() {
  int n, m;
  cin >> n >> m;
  while (1) {
    int r, c, x;
    cin >> r >> c >> x;
    if (r==0) break;
    int p = (r+c)%2;
    pfx[p][r][c] += x;
  }
  for (int p=0;p<=1;p++) {
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
      pfx[p][i][j] += pfx[p][i-1][j] + pfx[p][i][j-1] - pfx[p][i-1][j-1];
    }
  }
  while (1) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if (r1==0) break;
    int p=(r1+c1)%2;
    int sum1 = pfx[p][r2][c2] - pfx[p][r2][c1-1] - pfx[p][r1-1][c2] + pfx[p][r1-1][c1-1];
    int sum2 = pfx[!p][r2][c2] - pfx[!p][r2][c1-1] - pfx[!p][r1-1][c2] + pfx[!p][r1-1][c1-1];
    cout << sum1 - sum2 << '\n';
  }
}