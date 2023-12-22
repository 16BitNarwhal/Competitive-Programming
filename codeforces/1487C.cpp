#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    for (int i=0;i<n;i++) {
      for (int j=i+1;j<n;j++) {
        if (j-i < n/2) {
          cout << "1 ";
        } else if (j-i > n/2) {
          cout << "-1 ";
        } else {
          if (n&1) {
            cout << "1 ";
          } else {
            cout << "0 ";
          }
        }
      }
    }
    cout << '\n';
  }
}