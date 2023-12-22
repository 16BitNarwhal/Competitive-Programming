#include <bits/stdc++.h>
using namespace std;

struct board {
  char a[3][3];
  
  bool operator==(const board o) {
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) if (a[i][j]!=o.a[i][j]) return false;
    return true;
  }

  bool similar(const board o) {
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) {
      if (a[i][j]=='.') continue;
      if (a[i][j]!=o.a[i][j]) return false;
    }
    return true;
  }

  int winner() {
    for (int i=0;i<3;i++) {
      if (a[i][i]=='.') continue;
      bool haswin1 = a[i][0]==a[i][1] && a[i][1]==a[i][2];
      bool haswin2 = a[0][i]==a[1][i] && a[1][i]==a[2][i];
      if (haswin1 || haswin2) return a[i][i]=='X' ? 1 : 2;
    }
    if (a[1][1]=='.') return 0;
    bool haswin1 = a[0][0]==a[1][1] && a[1][1]==a[2][2];
    bool haswin2 = a[0][2]==a[1][1] && a[1][1]==a[2][0];
    if (haswin1 || haswin2) return a[1][1]=='X' ? 1 : 2;
    return 0;
  }

  bool isFull() {
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) if (a[i][j]=='.') return false;
    return true;
  }
};

board inp, cur;
string ans = "illegal";

void rec(int player) {
  
  if (!cur.similar(inp)) return;
  if (cur==inp) {
    int w = cur.winner();
    if (w==1) {
      ans = "the first player won";
    } else if (w==2) {
      ans = "the second player won";
    } else if (w==0 && cur.isFull()) {
      ans = "draw";
    } else if (w==0) {
      if (player==1) ans="first";
      else ans="second";
    }
  } else {
    if (cur.winner() != 0) return;
  }
  
  for (int i=0;i<3;i++) {
    for (int j=0;j<3;j++) {
      if (cur.a[i][j] == '.') {
        if (player==1) {

          cur.a[i][j] = 'X';
          rec(2);
          cur.a[i][j] = '.';

        } else {
          
          cur.a[i][j] = '0';
          rec(1);
          cur.a[i][j] = '.';

        }
      }
    }
  }
}

int main() {
  for (int i=0;i<3;i++) for (int j=0;j<3;j++) 
    cin >> inp.a[i][j];
  for (int i=0;i<3;i++) for (int j=0;j<3;j++)
    cur.a[i][j]='.';
  rec(1);
  cout << ans << '\n';
}