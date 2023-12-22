#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int a[MM], pre[MM], cnt0[MM];
int main() {
  int n, q;
  cin >> n >> q;
  int x=0;
  for (int i=1;i<=n;i++) {
    cin >> a[i];
    x ^= a[i];

    pre[i] = x;
    cnt0[i] = cnt0[i-1] + (a[i]==0);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (cnt0[r]-cnt0[l-1]==r-l+1) {
      cout << "0\n";
      continue;
    }
    if (pre[r] != pre[l-1]) {
      cout << "-1\n";
      continue;
    }
    if ((r-l+1)%2==1) {
      cout << "1\n";
      continue;
    }
    bool can=false;
    int ans = 2;
    for (int i=l;i<=r;i+=2) {
      if (pre[i] == pre[l-1] && pre[r] == pre[i]) {
        can=true;
        int cur = 2;
        if (cnt0[i]-cnt0[l-1]==i-l+1) cur--;
        if (cnt0[r]-cnt0[i]==r-i) cur--;
        ans = min(ans, cur);
      }
    }
    cout << (can ? ans : -1) << '\n';
  }
}