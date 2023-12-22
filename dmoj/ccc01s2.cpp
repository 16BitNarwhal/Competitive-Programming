#include <bits/stdc++.h>
using namespace std;
int ar[100][100];
int main() {
  int a, b;
  cin >> a >> b;
  char dir='s';
  int d=1,x=50,y=50;
  for (int i=a;i<=b;) {
    for (int k=0;k<2;k++) {
      for (int j=0;j<d;j++) { 
        ar[x][y] = i;
        if (dir=='s') x++;
        else if (dir=='n') x--;
        else if (dir=='e') y++;
        else if (dir=='w') y--;
        i++;
      }
      if (dir=='s') dir='e';
      else if (dir=='e') dir='n';
      else if (dir=='n') dir='w';
      else if (dir=='w') dir='s';
    }
    d++;
  }
  for (int i=0;i<100;i++) {
    bool flag=0;
    for (int j=0;j<100;j++) {
      if (ar[i][j]) {
        if (ar[i][j]<=b) {
          cout << ar[i][j] << ' ';
          flag=1;
        }
      }
    }
    if (flag) cout << '\n';
  }
}