#include <bits/stdc++.h>
using namespace std;
int qry(int i) {
  cout << "? " << i << '\n';
  cout.flush();
  int ret;cin>>ret;return ret;
}
int main() {
  int n;cin>>n;
  int l=1, r=n;
  while (l<r) {
    int m = (l+r)/2;
    if (qry(m) < qry(m+1)) {
      r = m;
    } else {
      l = m+1;
    }
  }
  cout << "! " << l << '\n';
}