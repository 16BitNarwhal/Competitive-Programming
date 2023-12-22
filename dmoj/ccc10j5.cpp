#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
#define xx first
#define yy second
int dst[9][9];
vector<pi> moves = {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
int main() {
  memset(dst, -1, sizeof(dst));
  int sx, sy, ex, ey;
  cin >> sx >> sy >> ex >> ey;
  queue<pi> q;
  q.push({sx,sy});
  dst[sx][sy] = 0;
  while (!q.empty()) {
    pi u = q.front();
    q.pop();
    if (u.xx==ex && u.yy==ey) {
      cout << dst[u.xx][u.yy] << endl;
      return 0;
    }
    for (pi move : moves) {
      pi v = {u.xx + move.xx, u.yy + move.yy};
      if (dst[v.xx][v.yy] == -1 && 
          v.xx >= 1 && v.xx <= 8 && 
          v.yy >= 1 && v.yy <= 8) {
        dst[v.xx][v.yy] = dst[u.xx][u.yy] + 1;
        q.push(v);
      }
    }
  }
}