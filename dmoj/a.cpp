#include <bits/stdc++.h>
using namespace std;
const int MM  = 2e5+2;
bool ar[3][MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;cin>>n;
  int cnt=0;
  for (int i=1;i<=2;i++) {
    for (int j=1;j<=n;j++) {
      cin >> ar[i][j];
      if (ar[i][j]) {
        cnt += 3;
        if (ar[i][j-1]) cnt -= 2;
        if (i==2) {
          if (j&1) {
            if (ar[1][j]) cnt -= 2;
          } else {
            if (ar[2][j]) cnt -= 0;
          }
        }
      }
    }
  }
  cout << cnt << '\n';
}