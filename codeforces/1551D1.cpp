#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    cin >> n >> m  >> k;
    if (n%2==0) {
      // if width is odd, make sure dominoes in mth column
      if (k%2==0 && (m%2==0 || 2*k <= n*(m-1))) {
        cout << "yes\n";
      } else {
        cout << "no\n";
      }
    } else {
      // enough dominoes for 1 row and leftovers must be even
      if (k >= m/2 && (k- (m/2))%2==0) {
        cout << "yes\n";
      } else {
        cout << "no\n";
      }
    }
  }
}
 