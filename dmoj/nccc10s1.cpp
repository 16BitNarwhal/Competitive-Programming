#include <bits/stdc++.h>
using namespace std;
string s[1001];
int n, k, ans=0;
bool anskey[11];
void solve(int i) {
  if (i==k) {
    int res=1e9;
    for (int i=0;i<n;i++) {
      int cnt=0;
      for (int j=0;j<k;j++) {
        char c = anskey[j] ? 'T' : 'F';
        if (s[i][j]==c) cnt++;
      }
      res = min(res, cnt);
    }
    ans = max(ans, res);
    return;
  }
  anskey[i] = true;
  solve(i+1);
  anskey[i] = false;
  solve(i+1);
}
int main() {
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> s[i]; 
  solve(0);
  cout << ans << '\n'; 
} 
// O(2^K * N * K)