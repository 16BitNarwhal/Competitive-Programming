#include <bits/stdc++.h>
using namespace std;
char c[404][404];
int t, n, m;
int pre[404][404];
int sum(int x1, int y1, int x2, int y2) {
  return pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1];
}
int main() {
  cin>>t;
  while(t--) { 
    cin >> n >> m; 
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) pre[i][j]=0;
    for (int i=1;i<=n;i++) { 
      for (int j=1;j<=m;j++) {
        cin >> c[i][j];
        pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + (c[i][j]=='1'); 
      } 
    }
    int ans=1e9;
    for (int x1=1;x1<=n;x1++) {
      for (int y1=1;y1<=m;y1++) {
        for (int x2=x1+4;x2<=n;x2++) {
          for (int y2=y1+3;y2<=m;y2++) {
            int inner = sum(x1+1,y1+1,x2-1,y2-1);
            int top = y2-y1-1 - sum(x1, y1+1, x1, y2-1);
            int bottom = y2-y1-1 - sum(x2, y1+1, x2, y2-1);
            int left = x2-x1-1 - sum(x1+1, y1, x2-1, y1);
            int right = x2-x1-1 - sum(x1+1, y2, x2-1, y2);  
            if (inner + top + bottom + left > 16) {
              break;
            } else {
              ans = min(ans, inner+top+bottom+left+right);
            }
          }
        }
      }
    }
    cout << ans << '\n';
  }
}