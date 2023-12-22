#include <bits/stdc++.h>
using namespace std;
struct video {
  int happy=0, time=1e9;
  bool operator<(const video o)const{
    if (happy == o.happy) return time > o.time;
    return happy < o.happy;
  } 
  video operator+(const video& o)const{
    return {happy+o.happy, time+o.time};
  }
};
int n, m, H[51], E[51], P[51];
video dp[51][1001];
int main() {
  cin >> n;
  for (int i=1;i<=n;i++) 
    cin >> H[i] >> E[i] >> P[i];
  cin >> m;
  for (int i=0;i<=m;i++) dp[0][i] = {0, 0};
  for (int i=1;i<=n;i++) {
    for (int t=0;t<=m;t++) {
      for (int j=P[i]*t;j<=m;j++) {
        int h = t*H[i] - t*(t-1)/2*E[i];
        if (h < 0) h = 0; 
        video add = {h, t};
        dp[i][j] = max(dp[i][j], dp[i-1][j-P[i]*t] + add);
      }
    }
  }
  cout << dp[n][m].happy << '\n' << dp[n][m].time << '\n';
}