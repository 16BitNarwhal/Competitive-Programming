#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> ar = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
  int A, B, N;
  cin >> A >> B >> N;
  for (int i=0;i<N;i++) {
    int x; cin>>x;
    ar.push_back(x);
  }
  sort(ar.begin(), ar.end());
  N = ar.size();
  vector<long long> dp(N);
  dp[0] = 1;
  for (int i=0;i<N;i++) {
    for (int j=i+1;j<N;j++) {
      if (ar[j]-ar[i] >= A && ar[j]-ar[i] <= B) {
        dp[j] += dp[i];
      }
    }
  }
  cout << dp[N-1] << endl;
}
