#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n, m, a[MM], b[MM];
int main() {
  cin >> n >> m;
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<m;i++) cin >> b[i];
  sort(a, a+n);
  sort(b, b+m);
  int i=0;
  for (int j=0;j<m;j++) {
    while (i<n && a[i]<b[j])
      i++;
    cout << i << ' ';
  }
}