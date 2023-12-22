#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) {
    int n, c;
    cin>>n>>c;
    vector<int> v(n), pfx(c+1, 0);
    vector<bool> vis(c+1, false);
    for (int &i:v) {
      cin>>i;
      pfx[i]++;
      vis[i] = true;
    }
    for (int i=1;i<=c;i++) {
      pfx[i] += pfx[i-1];
    }
    bool ans = true;
    for (int y=1;y<=c;y++) {
      if (!vis[y]) continue;
      for (int i=1;i*y<=c;i++) {
        int r = min(c, y*(i+1)-1);
        if (pfx[r] - pfx[y*i-1] > 0 && !vis[i]) {
          ans = false;
          break;
        }
      }
    }
    cout << (ans ? "Yes\n" : "No\n");
  }
}