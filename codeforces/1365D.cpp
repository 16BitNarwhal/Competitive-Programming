#include <bits/stdc++.h>
using namespace std;
string g[50];
bool vis[50][50]; 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    for (int i=0;i<n;i++) cin>>g[i];
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) {
        if (g[i][j]=='B') {
          if (i && g[i-1][j]=='.') g[i-1][j]='#';
          if (i<n-1 && g[i+1][j]=='.') g[i+1][j]='#';
          if (j && g[i][j-1]=='.') g[i][j-1]='#';
          if (j<m-1 && g[i][j+1]=='.') g[i][j+1]='#';
        }
      }
    }  
    for (int i=0;i<n;i++) fill(vis[i], vis[i]+m, 0);
    queue<pair<int,int>> q;
    if (g[n-1][m-1] != '#') {
      q.push({n-1,m-1});
      vis[n-1][m-1] = 1; 
    }
    while (!q.empty()) {
      pair<int,int> u = q.front();
      q.pop();
      int i = u.first, j = u.second; 
      if (i && g[i-1][j]!='#' && !vis[i-1][j]) {
        vis[i-1][j] = 1;
        q.push({i-1, j});
      }
      if (i<n-1 && g[i+1][j]!='#' && !vis[i+1][j]) {
        vis[i+1][j] = 1;
        q.push({i+1, j});
      }
      if (j && g[i][j-1]!='#' && !vis[i][j-1]) {
        vis[i][j-1] = 1;
        q.push({i, j-1});
      }
      if (j<m-1 && g[i][j+1]!='#' && !vis[i][j+1]) {
        vis[i][j+1] = 1;
        q.push({i, j+1});
      }
    }
    
    bool ans=1;
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) {
        if (g[i][j]=='G' && !vis[i][j])
          ans=0;
        else if (g[i][j]=='B' && vis[i][j])  
          ans=0;
      }
    }
    cout << (ans?"Yes\n":"No\n");
  }
}