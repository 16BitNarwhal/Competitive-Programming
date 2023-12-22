#include <iostream>
#include <math.h>

using namespace std;

int main() {
  int N, x, y, t1=0, t2=0, max=0, w;
  cin >> N;

  for(int i=0; i<N; i++) {
    cin >> x >> y;
    t1 += x;
    t2 += y;
    if(abs(t1-t2) > max) {
      max = abs(t1-t2);
      w = t1-t2<0 ? 2 : 1;
    }
  }

  cout << w << " " << max;
    
}

/*
5
140 82
89 134
90 110
112 106
88 90
*/