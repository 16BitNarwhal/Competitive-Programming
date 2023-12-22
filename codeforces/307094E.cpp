#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int n, s;
ll W[MM], C[MM];
int main() {
  cin >> n >> s;
  for (int i=0;i<n;i++) cin >> W[i];
  for (int i=0;i<n;i++) cin >> C[i];
  int l=0;
  ll w=0, c=0, ans=0;
  for (int r=0;r<n;r++) {
    w += W[r];
    c += C[r];
    while (w > s) {
      w -= W[l];
      c -= C[l];
      l++;
    }
    ans = max(ans, c);
  }
  cout << ans << '\n';
}