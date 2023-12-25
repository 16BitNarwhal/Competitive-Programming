#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll twos[1010][1010], fives[1010][1010];
char path[1010][1010];
ll pow2[35], pow5[15];
int izero=-1;
int jzero=-1;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  pow2[0] = pow5[0] = 1;
  for (int i=1;i<35;i++) pow2[i] = pow2[i-1] * 2;
  for (int i=1;i<15;i++) pow5[i] = pow5[i-1] * 5;

  int n; cin >> n;
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
      ll x;cin>>x;
      if (x==0) {
        izero = i;
        jzero = j;
      }
      int l=1,r=34;
      while (l<=r) {
        int m = (l+r)/2;
        if (x % pow2[m] == 0) {
          twos[i][j] = m;
          l = m+1;
        } else {
          r = m-1;
        }
      }
      l=1,r=14;
      while (l<=r) {
        int m = (l+r)/2;
        if (x % pow5[m] == 0) {
          fives[i][j] = m;
          l = m+1;
        } else {
          r = m-1;
        }
      }
    }
  }

  for (int i=1;i<=n;i++) {
    twos[i][1] += twos[i-1][1];
    path[i][1] = 'D';
    twos[1][i] += twos[1][i-1];
    path[1][i] = 'R';
  }
  for (int i=2;i<=n;i++) {
    for (int j=2;j<=n;j++) {
      if (twos[i-1][j] < twos[i][j-1]) {
        twos[i][j] += twos[i-1][j];
        path[i][j] = 'D';
      } else {
        twos[i][j] += twos[i][j-1];
        path[i][j] = 'R';
      }
    }
  }
  string two;
  int i=n,j=n;
  while (i!=1 || j!=1) {
    if (path[i][j]=='D') {
      i--;
      two = 'D' + two;
    } else {
      j--;
      two = 'R' + two;
    }
  }
  
  for (int i=1;i<=n;i++) {
    fives[i][1] += fives[i-1][1];
    path[i][1] = 'D';
    fives[1][i] += fives[1][i-1];
    path[1][i] = 'R';
  }
  for (int i=2;i<=n;i++) {
    for (int j=2;j<=n;j++) {
      if (fives[i-1][j] < fives[i][j-1]) {
        fives[i][j] += fives[i-1][j];
        path[i][j] = 'D';
      } else {
        fives[i][j] += fives[i][j-1];
        path[i][j] = 'R';
      }
    }
  }
  string five;
  i=n,j=n;
  while (i!=1 || j!=1) {
    if (path[i][j]=='D') {
      i--;
      five = 'D' + five;
    } else {
      j--;
      five = 'R' + five;
    }
  }

  if (izero != -1) {
    if (twos[n][n]>0 && fives[n][n]>0) {
      cout << "1\n";
      for (int i=1;i<izero;i++) cout << 'D';
      for (int j=1;j<jzero;j++) cout << 'R';
      for (int i=izero;i<n;i++) cout << 'D';
      for (int j=jzero;j<n;j++) cout << 'R';
      cout << '\n';
      return 0;
    }
  }
  
  if (twos[n][n] < fives[n][n]) {
    cout << twos[n][n] << '\n' << two << '\n';
  } else {
    cout << fives[n][n] << '\n' << five << '\n';
  }
}