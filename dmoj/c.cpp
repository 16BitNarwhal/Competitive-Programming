#include <bits/stdc++.h>
using namespace std;
const int MM = 2023;
char res[MM][MM];
int N, M, R, C;

char get_next(char c) {
  if (c == 'y') return 'a';
  return c+1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M >> R >> C;

  for (int i=1;i<=(N+1)/2;i++) {
    for (int j=1;j<=(M+1)/2;j++) {
      res[i][j] = (i+j-1)%26 + 'a';
    }
  }

  for (int i=(N+1)/2+1;i<=N;i++) {
    for (int j=1;j<=(M+1)/2;j++) {
      if (i <= R && j <= C) {
        res[i][j] = res[N-i+1][j]; // palindrome
      } else {
        res[i][j] = 'z'; // non palindrome
      }
    }
  }

  for (int i=1;i<=(N+1)/2;i++) {
    for (int j=(M+1)/2+1;j<=M;j++) {
      if (i <= R && j <= C) {
        res[i][j] = res[i][M-j+1]; // palindrome
      } else {
        res[i][j] = 'z'; // non palindrome
      }
    }
  }

  for (int i=R)

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

  if (!ok) {cout << "IMPOSSIBLE\n"; return 0;}
  for (int i=1;i<=N;i++) {
    for (int j=1;j<=M;j++) {
      cout << res[i][j];
    }
    cout << '\n';
  }
}