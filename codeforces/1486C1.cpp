#include <bits/stdc++.h>
using namespace std;
int n;
int qry(int l, int r) {
  cout << "? " << l << ' ' << r << '\n';
  cout.flush();
  int x; cin >> x;
  return x;
}
int main() {
  cin >> n;
  int x = qry(1, n);
  if (x!=1 && qry(1,x) == x) { 
    int l=1, r=x-1;
    while (l<=r) {
      int m = (l+r)/2;
      if (qry(m,x)==x) l = m+1;
      else r = m-1;
    }
    cout << "! " << r << '\n';
  } else {
    int l=x+1, r=n;
    while (l<=r) {
      int m = (l+r)/2;
      if (qry(x,m)==x) r = m-1;
      else l = m+1;
    }
    cout << "! " << l << '\n';
  }
}