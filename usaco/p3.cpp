#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int a[MM];
int main() {
  int n; cin >> n;
  for (int i=1;i<=n;i++) cin >> a[i];
  string s;
  int x=1;
  bool dir=1;
  while (true) {
    if ((dir==1 && a[x]>0) || (a[x]>a[x-1])) {
      dir=1;
      s+='R';
      a[x]--;
      x++;
    } else {
      dir=0;
      s+='L';
      a[x-1]--;
      x--;
    }
    if (a[x]==0 && x==1) break;
  }
  cout << s << '\n';
}