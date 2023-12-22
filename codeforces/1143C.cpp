#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int c[MM];
int main() {
  int n; cin>>n;
  for (int i=1;i<=n;i++) {
    int a,b;cin>>a>>b;
    if (!b && a>0) {
      c[i] = 1; c[a] = 1;
    }
    if (a==-1) c[i] = 1;
  }
  bool ans=0;
  for (int i=1;i<=n;i++) {
    if (!c[i]) {
      ans=true;
      cout << i << ' ';
    }
  }
  if (!ans) cout << "-1\n";
}