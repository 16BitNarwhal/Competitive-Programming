#include <bits/stdc++.h>
using namespace std;
int grid[1001][1001], vis[1001][1001];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      char c; cin >> c;
      grid[i][j] = (c=='#');
    }
  }
  bool can=true;
  bool empty1=false;
  for (int i=0;i<n;i++) {
    bool flag=false, has=false;
    for (int j=0;j<m;j++) {
      if (grid[i][j]) has=true;
      if (flag && grid[i][j]) can=false;
      if (grid[i][j] && !grid[i][j+1]) flag=true;
    }
    empty1 |= !has;
  }
  bool empty2=false;
  for (int j=0;j<m;j++) {
    bool flag=false, has=false;
    for (int i=0;i<n;i++) {
      if (grid[i][j]) has=true;
      if (flag && grid[i][j]) can=false;
      if (grid[i][j] && !grid[i+1][j]) flag=true;
    }
    empty2 |= !has;
  }
  if (empty1 != empty2) can=false;
  if (!can) {
    cout << "-1\n";
    return 0;
  }
  int ans=0;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      if (vis[i][j] || !grid[i][j]) continue;
      ans++;
      queue<pair<int,int>> q;
      q.push({i,j});
      vis[i][j]=1;
      while (!q.empty()) {
        int x=q.front().first, y=q.front().second;
        q.pop();
        if (x+1<n && grid[x+1][y] && !vis[x+1][y]) {
          vis[x+1][y]=1;
          q.push({x+1,y});
        }
        if (y+1<m && grid[x][y+1] && !vis[x][y+1]) {
          vis[x][y+1]=1;
          q.push({x,y+1});
        }
        if (x-1>=0 && grid[x-1][y] && !vis[x-1][y]) {
          vis[x-1][y]=1;
          q.push({x-1,y});
        }
        if (y-1>=0 && grid[x][y-1] && !vis[x][y-1]) {
          vis[x][y-1]=1;
          q.push({x,y-1});
        }
      }
    }
  }
  cout << ans << '\n';
}