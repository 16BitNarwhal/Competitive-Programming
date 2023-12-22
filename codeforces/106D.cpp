#include <bits/stdc++.h>
using namespace std;
char grid[1001][1001];
int sum[1001][1001];
char dir[100001];
int n, m, k, dis[100001];
bool check(int i, int j) {
  bool res=1;
  int y=i, x=j;
  for (int q=0;q<k;q++) { 
    if (dir[q]=='N') {
      if (sum[y][x]-sum[y-dis[q]-1][x]-sum[y][x-1]+sum[y-dis[q]-1][x-1]>0) {
        res=0; break;
      }
      y-=dis[q];
    } else if (dir[q]=='S') {
      if (sum[y+dis[q]][x]-sum[y-1][x]-sum[y+dis[q]][x-1]+sum[y-1][x-1]>0) {
        res=0; break;
      }
      y+=dis[q];
    } else if (dir[q]=='W') {
      if (sum[y][x]-sum[y][x-dis[q]-1]-sum[y-1][x]+sum[y-1][x-dis[q]-1]>0) {
        res=0; break;
      }
      x-=dis[q];
    } else {
      if (sum[y][x+dis[q]]-sum[y][x-1]-sum[y-1][x+dis[q]]+sum[y-1][x-1]>0) {
        res=0; break;
      }
      x+=dis[q];
    }
    if (x<0 || y<0 || y>=n || x>=m) {
      res=0; break;
    }
  }
  return res;
}
int main() { 
  ios::sync_with_stdio(0); cin.tie(0); 
  cin>>n>>m;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      cin>>grid[i][j];
      sum[i][j] = (grid[i][j]=='#');
      if (i) sum[i][j] += sum[i-1][j];
      if (j) sum[i][j] += sum[i][j-1];
      if (i && j) sum[i][j] -= sum[i-1][j-1]; 
    } 
  }
  cin>>k;
  for (int i=0;i<k;i++) 
    cin >> dir[i] >> dis[i];
  set<char> ans;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      if (grid[i][j] != '.' && grid[i][j] != '#') { 
        if (check(i,j)) {
          ans.insert(grid[i][j]);
        }
      }
    }
  }
  if (ans.empty()) {
    cout << "no solution\n";
  } else {
    for (char i : ans) {
      cout << i;
    }
  }
}