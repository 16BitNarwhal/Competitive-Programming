#include <bits/stdc++.h>
using namespace std;
int qry(int a, int b) {
  cout << "? " << a << " " << b << endl;
  int res; cin >> res;
  return res;
}
int main() {
  int t;cin>>t;
  while (t--) {
    int r = 0;
    for (int i=0;i<30;i++) {
      int a = (1<<i) - r;
      int b = a + (1<<(i+1));
      int res = qry(a, b);
      if (res == (1<<(i+1))) {
        r += 1<<i;
      }  
    }
    cout << "! " << r << endl;
  }
} 