#include <bits/stdc++.h>
using namespace std;
int r, c, m, grid[380][90], qry[30005]; 
int main() {
  cin >> r >> c;
  for (int i=0;i<r;i++) {
    string s;cin>>s;
    for (int j=0;j<c;j++) 
      grid[i][j] = (s[j]=='X');
  }
  cin >> m;
  for (int i=m-1;i>=0;i--) {
    char x;cin>>x;
    if (x=='F') qry[i]=0;
    else if (x=='L') qry[i]=1;
    else qry[i]=2;
  }
  for (int i=0;i<r;i++) {
    for (int j=0;j<c;j++) {
      if (grid[i][j]) continue;
      for (int dir=0;dir<4;dir++) {
        int x=i, y=j, d=dir;
        for (int q=0;q<m;q++) {
          if (qry[q]==0) {
            if (d==0) x++;
            else if (d==1) x--;
            else if (d==2) y++;
            else if (d==3) y--;
          } else if (qry[q]==2) {
            if (d==0) d=2;
            else if (d==1) d=3;
            else if (d==2) d=1;
            else if (d==3) d=0;
          } else {
            if (d==0) d=3;
            else if (d==1) d=2;
            else if (d==2) d=0;
            else if (d==3) d=1;
          }
          if (x<0 || x>=r || y<0 || y>=c || grid[x][y]==1) {
            break;
          } else if (q==m-1) {
            grid[i][j]=2;
          }
        }
      }
    }
  }
  for (int i=0;i<r;i++) {
    for (int j=0;j<c;j++) {
      if (grid[i][j]==0) cout << '.';
      else if (grid[i][j]==1) cout << 'X';
      else cout << '*';
    }
    cout << '\n';
  }
}