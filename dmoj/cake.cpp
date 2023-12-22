#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5005;
ll pfx[MM][MM];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i=0;i<k;i++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    pfx[r1][c1]++;
    pfx[r2+1][c2+1]++;
    pfx[r1][c2+1]--;
    pfx[r2+1][c1]--;
  }
  for (int cnt=0;cnt<2;cnt++) 
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      pfx[i][j] += pfx[i-1][j] + pfx[i][j-1] - pfx[i-1][j-1];
    }
  } 
  int q;cin>>q;
  while (q--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << pfx[r2][c2] - pfx[r2][c1-1] - pfx[r1-1][c2] + pfx[r1-1][c1-1] << '\n';
  }
}