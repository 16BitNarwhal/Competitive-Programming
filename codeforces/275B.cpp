#include <bits/stdc++.h>
using namespace std;
int n, m; 
bool grid[55][55];
int main() {
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      char c;cin>>c;
      grid[i][j] = (c=='B');
    }
  }
  bool ans=true;
  for (int i=0;i<n;i++) {
    int cnt=0;
    for (int j=0;j<m;j++) {
      if (grid[i][j] && (j==0 || !grid[i][j-1])) cnt++;
    }
    if (cnt>=2) ans=false;
  }
  for (int j=0;j<m;j++) {
    int cnt=0;
    for (int i=0;i<n;i++) {
      if (grid[i][j] && (i==0 || !grid[i-1][j])) cnt++;
    }
    if (cnt>=2) ans=false;
  }
  for (int i1=0;i1<n;i1++) for (int j1=0;j1<m;j1++) {
    if (!grid[i1][j1]) continue;
    for (int i2=0;i2<n;i2++) for (int j2=0;j2<m;j2++) {
      if (!grid[i2][j2]) continue;
      if (!grid[i1][j2] && !grid[i2][j1]) ans=false;
    }
  }
  cout << (ans ? "YES" : "NO") << '\n';
}