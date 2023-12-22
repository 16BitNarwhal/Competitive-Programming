#include <bits/stdc++.h>
using namespace std;
const int MM = 102;
// dp[i operations][j operations] = # lines (-1 if not possible)
int a[MM], b[MM], dp[MM][MM]; 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(dp, -1, sizeof dp);
    int n, m, k;
    cin >> k >> n >> m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    int i1=0, i2=0; // a and b iterators
    dp[0][0] = k;
    for (int i=0;i<=n;i++) {
      for (int j=0;j<=m;j++) { 
        if (a[i+1] <= dp[i][j]) 
          dp[i+1][j] = max(dp[i+1][j], dp[i][j] + (a[i+1]==0));
        else dp[i+1][j] = max(dp[i+1][j], -1);
        if (b[j+1] <= dp[i][j]) 
          dp[i][j+1] = max(dp[i][j+1], dp[i][j] + (b[j+1]==0));
        else dp[i][j+1] = max(dp[i][j+1], -1); 
      } 
    } 
    if (dp[n][m]==-1) cout << "-1\n";
    else {
      vector<pair<int,int>> path;
      queue<vector<pair<int,int>>> q;
      q.push({{0,0}});
      while (!q.empty()) {
        path = q.back(); q.pop();
        int i = path.back().first, j = path.back().second;
        if (i==n && j==m) break;
        if (i<n && dp[i+1][j]>=0) {
          vector<pair<int,int>> npath = path;
          npath.push_back({i+1, j});
          q.push(npath); 
        }
        if (j<m && dp[i][j+1]>=0) {
          vector<pair<int,int>> npath = path;
          npath.push_back({i, j+1});
          q.push(npath);
        }
      }
      int i=0,j=0;
      for (auto p:path) {
        if (p.first==0 && p.second==0) continue;
        if (p.first==i) {
          cout << b[p.second] << ' ';
          j = p.second;
        } else {
          cout << a[p.first] << ' ';
          i = p.first;
        } 
      }
      cout << '\n';
    }
  }
}
// pls work