#include <bits/stdc++.h>
using namespace std;
int P[2002][3], V[2002][3], dp[10010];
int main() {
  int N, T;
  cin >> N >> T;
  for (int i=0;i<N;i++) 
    for (int j=0;j<3;j++) 
      cin >> P[i][j] >> V[i][j];
  for (int i=0;i<N;i++) {
    for (int j=T;j>=0;j--) {
      for (int k=0;k<3;k++) {
        if (j<P[i][k]) continue;
        dp[j] = max(dp[j], dp[j-P[i][k]] + V[i][k]);
      }
    }
  }
  cout << dp[T] << '\n';
}