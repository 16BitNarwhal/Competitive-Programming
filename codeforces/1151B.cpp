#include <bits/stdc++.h>
using namespace std;
const int MM = 505;
int n,m,a[MM][MM];
int main() {
  cin >> n >> m;
  for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin>>a[i][j];
  int x = 0;
  for (int i=0;i<n;i++) 
    x ^= a[i][0];
  if (x==0) { 
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) {
        if (a[i][j] != a[i][0]) {
          cout << "TAK\n";
          for (int ii=0;ii<n;ii++) {
            if (ii==i) cout << j+1 << '\n';
            else cout << "1\n";
          }
          return 0;
        }
      }
    }
    cout << "NIE\n";
  } else {
    cout << "TAK\n";
    for (int i=0;i<n;i++) cout<<"1 ";
  }
  
}