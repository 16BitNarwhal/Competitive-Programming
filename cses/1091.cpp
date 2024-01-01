#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+2;
int t[MM];
int main() {
  int n,m;
  cin >> n >> m;
  multiset<int> h;
  for (int i=0;i<n;i++) {
    int x;cin>>x;
    h.insert(x);
  }
  for (int i=0;i<m;i++) cin >> t[i];
  
  for (int i=0;i<m;i++) {
    auto j = h.upper_bound(t[i]);
    if (j == h.begin()) {
      cout << -1 << endl;
      continue;
    }
    j--;
    if (*j > t[i] ) {
      cout << -1 << endl;
    } else {
      cout << *j << endl;
      h.erase(j);
    }
  }
}