#include <bits/stdc++.h>
using namespace std;
bool grid[101][101][11];
int dst[101][101][11];
struct pos {
  int x, y, z;
  friend ostream& operator<<(ostream& os, const pos& p) {
    os << "(" << p.x << "," << p.y << "," << p.z << ")";
    return os;
  }
};
vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
int main() {
  int R, C, T;
  cin >> R >> C >> T; 
  pos s, e;
  for (int i=0;i<T;i++) {
    for (int j=0;j<R;j++) {
      for (int k=0;k<C;k++) {
        char c;cin>>c;
        grid[j][k][i] = (c!='X');
        if (c=='A') s={j,k,i};
        if (c=='B') e={j,k,i};
      }
    }
  }
  memset(dst, -1, sizeof dst);
  queue<pos> q;
  q.push(s);
  dst[s.x][s.y][s.z]=0;
  int ans=-1; 
  while (!q.empty()) {
    pos u = q.front();
    q.pop(); 
    if (u.x==e.x && u.y==e.y && u.z==e.z) {
      ans = dst[u.x][u.y][u.z];
      break;
    }
    for (auto [dx, dy]: dirs) {
      int nx = u.x+dx, ny = u.y+dy;
      if (nx<0 || nx>=R || ny<0 || ny>=C) continue;
      if (grid[nx][ny][u.z] && dst[nx][ny][u.z]==-1) {
        dst[nx][ny][u.z] = dst[u.x][u.y][u.z]+1;
        q.push({nx,ny,u.z});
      }
    }
    for (int nz=0;nz<T;nz++) {
      if (u.z==nz) continue;
      if (grid[u.x][u.y][nz] && dst[u.x][u.y][nz]==-1) {
        dst[u.x][u.y][nz] = dst[u.x][u.y][u.z]+1;
        q.push({u.x,u.y,nz});
      }
    }
  }
  cout << ans << '\n';
}