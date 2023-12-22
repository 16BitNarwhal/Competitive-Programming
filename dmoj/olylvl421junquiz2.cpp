#include <bits/stdc++.h>
using namespace std; 
const int MM = 2e6+1;
typedef long long ll;
int N, cap;
ll dp[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> cap; 
  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  for (int i=1;i<=N;i++) {
    int w, v; cin>>v>>w;
    for (int j=MM;j>=v;j--) {
      dp[j] = min(dp[j], dp[j-v] + w);
    }
  }
  for (int i=MM-1;i>=0;i--) {
    if (dp[i] <= cap) {
      cout << i; break;
    }
  }
}