#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int a[MM], res[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) { 
    memset(a, 0, sizeof a);
    memset(res, 0, sizeof res);
    int n;cin>>n;
    for (int i=1;i<=n;i++) {
      cin >> a[i];
      int x = 0;
      for (int j=0;j<30;j++) {
        if (a[i-1] & (1<<j)) {
          if (!(a[i] & (1<<j)))
            x |= (1<<j);
        }
      }
      cout << x << ' ';
      a[i] |= a[i-1];
    }
    cout << '\n';
  }
}