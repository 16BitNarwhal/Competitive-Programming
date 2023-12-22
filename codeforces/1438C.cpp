#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=m;j++) {
        int x;cin>>x;
        if (x%2 != (i+j)%2) x++;
        cout << x << ' ';
      }
      cout << '\n';
    }
  }
}