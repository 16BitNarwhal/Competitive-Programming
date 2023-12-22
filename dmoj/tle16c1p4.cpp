#include <bits/stdc++.h>
using namespace std;
int val[101], dst[101][101];
bool active[101];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  memset(dst, 0x3f, sizeof(dst));
  for (int i=1;i<=n;i++) cin >> val[i];
  for (int i=0;i<m;i++) {
    int u, v, w;
    cin >> u >> v >> w;
    dst[u][v] = w;
    dst[v][u] = w;
  }
  for (int i=1;i<=n;i++) dst[i][i] = 0;
  // floyd warshall all pairs shortest path
  for (int k=1;k<=n;k++) {
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
        dst[i][j] = min(dst[i][j], dst[i][k]+dst[k][j]);
  }
  // complete search all answers
  int ans=0;
  for (int a=1;a<=n;a++) {
    for (int b=a+1;b<=n;b++) {
      for (int c=b+1;c<=n;c++) {
        memset(active, 0, sizeof(active));
        for (int i=1;i<=n;i++) 
          if (dst[a][i] <= k) active[i] = true; 
        for (int i=1;i<=n;i++) 
          if (dst[b][i] <= k) active[i] = true; 
        for (int i=1;i<=n;i++)  
          if (dst[c][i] <= k) active[i] = true; 
        int sum=0;
        for (int i=1;i<=n;i++) {
          sum += active[i] ? val[i] : 0;
        }
        ans = max(ans, sum);
      }
    }
  }
  cout << ans << endl;
}