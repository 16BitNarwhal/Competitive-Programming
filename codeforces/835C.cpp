#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
ll g[101][101][11];
vector<int> pt[101][101];
int n, q, c;
int main() {
  cin >> n >> q >> c;
  c++;
  for (int i=0;i<n;i++) {
    int x, y, s;
    cin >> x >> y >> s;
    pt[x][y].push_back(s);
  }
  for (int i=0;i<c;i++) {
    for (int x=1;x<=100;x++) {
      for (int y=1;y<=100;y++) {
        for (int e : pt[x][y]) {
          g[x][y][i] += (e+i) % c; 
        }
        g[x][y][i] += g[x-1][y][i] + g[x][y-1][i] - g[x-1][y-1][i];
      }
    }
  }
  while (q--) {
    int t, x1, y1, x2, y2;
    cin >> t >> x1 >> y1 >> x2 >> y2;
    t %= c;
    ll ans = g[x2][y2][t] - g[x2][y1-1][t] - g[x1-1][y2][t] + g[x1-1][y1-1][t];
    cout << ans << '\n';
  }
}