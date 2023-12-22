#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int ar[MM], res[MM], back[MM];
void solve() {
  int n;cin>>n;
  fill(res, res+n+1, -1);
  fill(back, back+n+1, -1);
  int ans=0;
  for (int i=1;i<=n;i++) {
    cin >> ar[i];
    if (back[ar[i]] < 0) {
      res[i] = ar[i];
      back[ar[i]] = i;
      ans++;
    }
  }
  vector<int> start, end;
  for (int i=1;i<=n;i++) {
    if (back[i]>0) continue;
    int j = i;
    while (res[j]>0)
      j = res[j];
    start.push_back(i);
    end.push_back(j);
  }
  if (!start.empty()) {
    if (start.size() > 1 || start[0] != end[0]) {
      for (int i=0;i<start.size();i++)
        res[end[i]] = start[(i+1) % start.size()];
        // end of this path -> start of next path
    } else {
      int x = start[0];
      int y = ar[x];
      res[back[y]] = x;
      res[x] = y;
    }
  }
  cout << ans << '\n';
  for (int i=1;i<=n;i++) cout << res[i] << ' ';
  cout << '\n';
}
int main() {
  int t;cin>>t;
  while(t--) solve();
}