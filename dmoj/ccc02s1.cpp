#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x; cin>> x;
  int mn=1e9, cnt=0;
  for (int i=0;i*a<=x;i++) {
    for (int j=0;j*b<=x;j++) {
      for (int k=0;k*c<=x;k++) {
        for (int l=0;l*d<=x;l++) {
          if (i*a+j*b+k*c+l*d==x) {
            mn = min(mn, i+j+k+l);
            cnt++;
            printf("# of PINK is %d # of GREEN is %d # of RED is %d # of ORANGE is %d\n", i, j, k, l);
          }
        }
      }
    }
  }
  printf("Total combinations is %d.\nMinimum number of tickets to print is %d.", cnt, mn);
}