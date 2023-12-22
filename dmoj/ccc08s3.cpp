#include <bits/stdc++.h>
using namespace std;
int dst[21][21];
char grid[21][21];
vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
vector<int> dirs1D = {-1,1};
int main() {
  int t; cin >> t;
  while (t--) {
    int r, c;
    cin >> r >> c;
    for (int i=1;i<=r;i++) {
      for (int j=1;j<=c;j++) 
        cin >> grid[i][j]; 
    }
    
    memset(dst, -1, sizeof(dst));
    dst[1][1] = 1;
    queue<pair<int,int>> q;
    q.push({1,1});
    while (!q.empty()) {
      auto p = q.front(); q.pop();
      int x = p.first, y = p.second;
      if (x == r && y == c) break;
      vector<pair<int,int>> next;
      if (grid[x][y]=='+') {
        for (auto dir: dirs) { 
          next.push_back({x+dir.first, y+dir.second});
        }
      } else if (grid[x][y]=='-') {
        for (auto dir: dirs1D) {
          next.push_back({x, y+dir});
        }
      } else if (grid[x][y]=='|') {
        for (auto dir: dirs1D) {
          next.push_back({x+dir, y});
        }
      } else {
        cout << "error" << '\n';
      }
      for (auto [nx,ny] : next) {
        if (nx<1 || nx>r || ny<1 || ny>c) continue;
        if (grid[nx][ny]!='*' && dst[nx][ny]==-1) {
          dst[nx][ny] = dst[x][y] + 1;
          q.push({nx,ny});
        }
      }
    }
    cout << dst[r][c] << '\n';
  }
}