#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
int ar[MM];
bool vis[MM];
int main() {
  int n; cin >> n;
  int mx=0;
  for (int i=0;i<n;i++) {
    cin >> ar[i];
    mx = max(mx, ar[i]);
    vis[ar[i]]=true;
  }
  int ans=0;
  for (int i=1;i<=mx;i++) {
    if (vis[i]) continue;
    int g=0;
    for (int j=i;j<=mx;j+=i) {
      if (!vis[j]) continue;
      g = gcd(g, j);
    }
    ans += (g==i);
  }
  cout << ans << '\n';
}