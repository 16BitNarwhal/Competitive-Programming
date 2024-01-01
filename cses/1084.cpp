#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+2;
int a[MM], b[MM];
int main() {
  int n, m, k;
  cin >> n >> m >> k;

  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<m;i++) cin >> b[i];

  sort(a, a+n);
  sort(b, b+m);

  int cnt=0;
  for (int i=0,j=0;i<n && j<m;) {
    if (abs(a[i]-b[j]) <= k) {
      cnt++;
      i++; j++;
    } else if (a[i] < b[j]) {
      i++;
    } else {
      j++;
    }
  }
  cout << cnt << endl;
}