#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
int n, ar[MM];
map<int,int> cnt;
bool vis[MM];
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    cnt.clear();
    fill(vis, vis+n+1, false);
    bool ans = false;
    for (int i=1;i<=n;i++) {
      cin>>ar[i];
      cnt[ar[i]]++;
      if (cnt[ar[i]]>=2)
        ans = true;
    }
    if (ans) {
      cout << "YES\n";
      continue;
    }
    int c=0;
    for (int i=1;i<=n;i++) {
      if (vis[i]) continue;
      int j=i;
      while (!vis[j]) {
        vis[j] = true;
        j = ar[j];
        c++;
      }
      c--;
    }
    cout << (c%2==0 ? "YES" : "NO") << '\n';
  }
}