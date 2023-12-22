#include <bits/stdc++.h>
using namespace std;
const int MM = 2023;
char res[MM][MM], tmp[MM][MM];
int main() {
  int N, M, R, C;
  cin >> N >> M >> R >> C;
  bool swapped=false;
  if (R==1 && C==1) {
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
  // no idea whats going on :)
  } else {
    if (C==0 || C==M) {
      swapped = !swapped;
      swap(N, M);
      swap(R, C);
    }
    if (R==0) {
      if (C==0) {
        for (int j=1;j<=N;j++) {
          for (int i=1;i<=M;i++) {
            res[j][i] = (i+j)%13 + 'a';
          }
        }
      } else {
        for (int j=1;j<=N;j++) {
          for (int i=1;i<=M;i++) {
            if (j==1) res[1][i] = (i-1)%13 + 'a'; // cyclic (non palindrome)
            else res[j][i] = 'x';
          }
        }
        for (int j=2;j<=N;j++) {
          for (int i=1;i<=C;i++) {
            res[j][i] = res[1][i];
          }
        }
      }
    } else if (R>0 && R<N) { // 0 < R < N
      for (int j=1;j<=N;j++) {
        for (int i=1;i<=M;i++) {
          if (j<=R) res[j][i] = 'x';
          else res[j][i] = (i-1)%13 + 'a';
        }
      }
      for (int j=2;j<=N;j++) {
        for (int i=1;i<=C;i++) {
          res[j][i] = res[1][i];
        }
      }
    } else if (R==N) {
      for (int j=1;j<=N;j++) {
        for (int i=1;i<=M;i++) {
          res[j][i] = (j-1)%13+'a';
        }
      }
      if (M&1) {
        if (C&1) {
          for (int i=1;i<=N;i++) {
            res[i][M/2+1] = 'x'; // enable middle col
          }
        }
      } else if (C&1) {
        cout << "IMPOSSIBLE\n";
        return 0;
      }
      // from the middle, enable cols moving out
      for (int j=1;j<=N;j++) {
        for (int i=1;i<=C/2;i++) {
          res[j][(M+1)/2+i] = res[j][M/2-i+1] = 'x';
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
        tmp[j][i] = res[i][j];
      }
    }
    swap(N, M);
    for (int i=1;i<=N;i++) {
      for (int j=1;j<=M;j++) {
        res[i][j] = tmp[i][j];
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