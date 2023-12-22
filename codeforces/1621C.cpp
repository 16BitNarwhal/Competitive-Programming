#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+4;
bool vis[MM];
int ar[MM];
int qry(int x) {
  cout << "? " << x << endl;
  int ret; cin >> ret;
  return ret;
}
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    fill(vis, vis+n+1, 0);
    for (int i=1;i<=n;i++) {
      if (vis[i]) continue;
      int prev=qry(i), j=qry(i);
      vis[prev] = 1;
      ar[prev] = j;
      while (!vis[j]) {
        vis[j]=1;
        prev = j;
        j = qry(i);
        if (prev != -1)
          ar[prev] = j;
      }
    }
    cout << "! ";
    for (int i=1;i<=n;i++) cout << ar[i] << ' ';
    cout << endl;
  }
}