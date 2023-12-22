#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, Q;
int dir[1505][1505]; // 0: right, 1: down
ll cnt[1505][1505], cst[1505][1505]; // got lazy with cst ;D
int main() {
  cin >> N;
  for (int i=1;i<=N;i++) {
    string s;cin>>s;
    for (int j=1;j<=N;j++) {
      if (s[j-1]=='R') dir[i][j] = 0;
      else dir[i][j] = 1;
    }
    cin >> cst[i][N+1];
  }
  for (int i=1;i<=N;i++) {
    cin >> cst[N+1][i];
  }
  for (int i=1;i<=N;i++) {
    for (int j=1;j<=N;j++) {
      if (dir[i][j]==0) {
        cnt[i][j+1] += cnt[i][j] + 1; // move right, add this cow
      } else {
        cnt[i+1][j] += cnt[i][j] + 1; // move down, add this cow
      }
    }
  }

  // for (int i=1;i<=N;i++) cout << cst[i][N+1] << " ";cout << endl;
  // for (int i=1;i<=N;i++) cout << cst[N+1][i] << " ";cout << endl;
  // for (int i=1;i<=N+1;i++) {
  //   for (int j=1;j<=N+1;j++) {
  //     cout << cnt[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  
  ll total_cost = 0;
  for (int i=1;i<=N;i++) total_cost += cst[i][N+1]*cnt[i][N+1] + cst[N+1][i]*cnt[N+1][i];

  cout << total_cost << "\n";
  cin >> Q;
  while (Q--) {
    int x, y;cin>>x>>y;
    int cx = x, cy = y;
    while (cx<=N && cy<=N) {
      if (dir[cx][cy]==0) {
        cy++;
      } else {
        cx++;
      }
      cnt[cx][cy] -= cnt[x][y] + 1;
    }
    total_cost -= (cnt[x][y]+1)*cst[cx][cy];
    
    dir[x][y] ^= 1;
    cx = x, cy = y;
    while (cx<=N && cy<=N) {
      if (dir[cx][cy]==0) {
        cy++;
      } else {
        cx++;
      }
      cnt[cx][cy] += cnt[x][y] + 1;
    }
    total_cost += (cnt[x][y]+1)*cst[cx][cy];

    cout << total_cost << endl;
  }
}