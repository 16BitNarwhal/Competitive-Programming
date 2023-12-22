// https://atcoder.jp/contests/dp/tasks/dp_f
#include <bits/stdc++.h>
using namespace std;
int dp[3001][3001];
pair<int,int> from[3001][3001];
ostream& operator<<(ostream& os, const pair<int,int>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
int main() { 
  string s1, s2;
  cin >> s1 >> s2;
  int n=s1.size(), m=s2.size();
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      if (s1[i-1]==s2[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
      }
    } 
  }
  string res="";
  int i=n, j=m;
  while (i && j) {
    if (s1[i-1] == s2[j-1]) {
      res += s1[i-1];
      i--; j--;
    } else if (dp[i-1][j] > dp[i][j-1]) {
      i--;
    } else {
      j--;
    }
  }
  reverse(res.begin(), res.end());
  cout << res << '\n'; 
}
 