#include <bits/stdc++.h>
using namespace std;
int V[1001], H[1001], dp[1001];
int main() {
  int N, T;
  cin >> N >> T;
  for (int i=1;i<=N;i++) {
    cin >> V[i] >> H[i];
  }
  for (int i=1;i<=N;i++) {
    for (int j=T;j>=H[i];j--) {
      dp[j] = max(dp[j], dp[j-H[i]]+V[i]);
    }
  }
  cout << dp[T] << '\n';
}