#include <bits/stdc++.h>
using namespace std;
// dp[floor][exit to left]
int n,m,dp[20][2];
string s[20];
int main() {
  cin >> n >> m;
  for (int i=0;i<n;i++) cin>>s[n-i-1];
  m+=2;
  int has_light=0;
  for (int i=0;i<n;i++) 
    for (int j=0;j<m;j++) 
      if (s[i][j]=='1') has_light = max(has_light, i); 
  n = has_light+1;
  for (int floor=0;floor<n;floor++) {
    int far_right_light=0;
    int far_left_light=m-1;
    for (int i=0;i<m;i++) {
      if (s[floor][i]=='1') {
        far_right_light = max(i, far_right_light);
        far_left_light = min(i, far_left_light);
      }
    }
    int from_left = ((floor>0)?dp[floor-1][0]:0) + far_right_light;
    int from_right = ((floor>0)?dp[floor-1][1]:1e9) + m-1-far_left_light;

    if (floor==n-1) {
      cout << min(from_left, from_right) << '\n';
    }

    dp[floor][0] = 1+min(from_left + far_right_light, from_right + far_left_light);
    dp[floor][1] = 1+min(from_left + m-1-far_right_light, from_right + m-1-far_left_light);
  } 
}