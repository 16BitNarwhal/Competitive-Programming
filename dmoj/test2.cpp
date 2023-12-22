#include <bits/stdc++.h>
using namespace std;
const int MM = 2023;
char res[MM][MM];
char tmp[MM][MM];
int N, M, R, C;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M >> R >> C;

  for (int i=1;i<=N;i++) {
    for (int j=1;j<=M;j++) {
      res[i][j] = 'a';
    }
  }

  for (int i=R+1;i<=N;i++) {
    for (int j=C+1;j<=M;j++) {
      res[i][j] = 'b';
    }
  }

  bool swapped = false;
  if (C==M) {
    swapped = !swapped;
    swap(N, M);
    swap(R, C);
  }

  if (R==N) {
    for (int i=1;i<=N;i++) {
      for (int j=1;j<=M;j++) {
        res[i][j] = 'a';
      }
    }
    int X = M-C; // num to "disable"
    if (M&1) {
      if (X&1) {
        // "disable" the middle column
        res[1][M/2+1] = 'b';
        X--;
      } else {
        // not possible
        cout << "IMPOSSIBLE\n";
        return 0;
      }
    }
    for (int i=1;i<=X/2;i++) {
      res[1][M/2+1+i] = 'b';
      res[1][M/2+1-i] = 'b';
    }
  }

  if (C==0) {
    swapped = !swapped;
    swap(N, M);
    swap(R, C);
  }

  if (R==0) {
    if (C==0) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    for (int i=1;i<=N;i++) {
      for (int j=1;j<=M;j++) {
        res[i][j] = 'a';
      }
    }
    for (int i=1;i<=N;i++) {
      res[i][1] = 'b';
    }
    int X = M-C; // num to "disable"
    for (int i=2;i<=X+1;i++) {
      res[1][i] = 'c';
    }

    if (C==M) {
      for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
          res[i][j] = ((j-1)%3)+'f';
        }
      }
    }
  }

  bool ok = true;
  int cnt=0;
  for (int i=1;i<=N;i++) {
    bool ispal = true;
    for (int j=1;j<=M/2;j++) {
      if (res[i][j] != res[i][M-j+1]) {
        ispal = false;
        break;
      }
    }
    if (ispal) cnt++;
  }
  if (cnt != R) ok = false;
  cnt=0;
  for (int j=1;j<=M;j++) {
    bool ispal = true;
    for (int i=1;i<=N/2;i++) {
      if (res[i][j] != res[N-i+1][j]) { 
        ispal = false;
        break;
      }
    }
    if (ispal) cnt++;
  }
  if (cnt != C) ok = false;

  if (swapped) {
    for (int i=1;i<=N;i++) {
      for (int j=1;j<=M;j++) {
        tmp[i][j] = res[i][j];
      } 
    }
    swap(N, M);
    swap(R, C);
    for (int i=1;i<=N;i++) {
      for (int j=1;j<=M;j++) {
        res[i][j] = tmp[j][i];
      }
    }
  }
  if (!ok) {cout << "IMPOSSIBLE\n"; return 0;}
  for (int i=1;i<=N;i++) {
    for (int j=1;j<=M;j++) {
      cout << res[i][j];
    }
    cout << '\n';
  }
}