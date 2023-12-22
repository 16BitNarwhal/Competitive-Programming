#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    int l, r, k;
    cin >> l >> r >> k;
    if (l==r) {
      cout << (l==1 ? "NO\n" : "YES\n");
      continue;
    }
    if (l%2==0) l++;
    if (r%2==0) r--;
    if ((r-l+1)/2 < k) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}