#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5+3;
int n, m;
long long a[MM], b[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  cin >> m;
  for (int i=0;i<m;i++) cin >> b[i];
  int i=0,j=0,ans=0;
  while (i<n && j<m) {
    if (a[i]==b[j]) i++,j++,ans++;
    else if (a[i]<b[j]) {
      a[++i] += a[i-1];
    } else {
      b[++j] += b[j-1];
    }
  }
  if (i==n && j==m) cout << ans << '\n';
  else cout << "-1\n";
}