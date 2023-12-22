#include <bits/stdc++.h>
using namespace std;
const int MM = 5e4+2;
int N, Q, ar[MM], mx[MM][16], mn[MM][16];
void init() {
  for (int i=0;i<N;i++) 
    mx[i][0] = mn[i][0] = ar[i];
  
  for (int j=1;j<16;j++) {
    for (int i=0;i+(1<<j) <= N;i++) {
      mx[i][j] = max(mx[i][j-1], mx[i + (1<<(j-1))][j-1]);
      mn[i][j] = min(mn[i][j-1], mn[i + (1<<(j-1))][j-1]);
    }
  }
}
int q(int l, int r) {
  int a = mx[l][0];
  int b = mn[l][0];
  for (int j=16;j>=0;j--) {
    if ((1<<j) <= r-l+1) {
      a = max(a, mx[l][j]);
      b = min(b, mn[l][j]);
      l += (1<<j);
    }
  }
  return a-b;
}
int main() { 
  cin>>N>>Q;
  for (int i=0;i<N;i++) cin >> ar[i];
  init();
  while (Q--) {
    int l, r; cin>> l >> r;
    l--; r--;
    cout << q(l, r) << '\n';
  }
}