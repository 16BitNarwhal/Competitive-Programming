#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int n, m, l[MM];
ll suf[MM]; 
int main() {
  cin >> n >> m;
  for (int i=1;i<=m;i++) {
    cin >> l[i];
    if (l[i] + i - 1 > n) {
      cout << "-1\n";
      return 0;
    } 
  }
  for (int i=m;i>=1;i--)
    suf[i] = suf[i+1] + l[i];

  if (suf[1] < n) {
    cout << "-1\n";
    return 0;
  }
  
  for (int i=1;i<=m;i++) {
    cout << max(n - suf[i] + 1, 1LL*i) << ' ';
  }
} 