#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    // a > b
    int q = a/(b+1);
    int r = a%(b+1);
    for (int i=0;i<b+1;i++) {
      for (int j=0;j<q;j++)
        cout << "R";
      if (i<r) cout << "R";
      if (i<b) cout << "B";
    }
    cout << '\n';
  }
}