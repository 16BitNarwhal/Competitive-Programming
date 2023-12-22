#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int R[MM], C[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    fill(R, R+m+1, 0);
    fill(C, C+m+1, 0);
    int lst = -1e9;
    int cntC=0;
    for (int i=0;i<n*m;i++) {
      char c;cin>>c;
      if (c=='1') {
        lst = i;
        if (C[i%m]==0) {
          C[i%m] = 1;
          cntC++;
        }
      }
      if (i-lst < m) {
        R[i%m]++;
      }
      cout << (R[i%m]+cntC) << ' ';
    }
    cout << '\n';
  }
}