#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int a[MM], b[MM];
int main() {
  int n;cin>>n;
  for (int i=1;i<=n;i++) {
    cin >> a[i];
    a[i] += a[i-1];
  }
  for (int i=1;i<=n;i++) {
    cin >> b[i];
    b[i] += b[i-1];
  }
  for (int i=n;i>=1;i--) {
    if (a[i]==b[i]) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << "0\n";
}