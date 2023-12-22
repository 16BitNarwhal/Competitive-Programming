#include <bits/stdc++.h>
using namespace std;
int pow2[20];
int main() {
  pow2[0] = 1;
  for (int i=1;i<20;i++) pow2[i] = pow2[i-1]*2;
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    bool flag=false;
    for (int i=n-1;i>=1;i--) {
      cout << i << ' ';
      if (!flag) 
      for (int p : pow2) {
        if (p==i) {
          cout << "0 ";
          flag = true;
          break;
        }
      }
    }
    if (!flag) cout << "0 ";
    cout << '\n';
  }
}