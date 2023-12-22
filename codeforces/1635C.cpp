#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
struct op {
  int x, y, z;
};
int n, ar[MM];
int main() {
  int t;cin>>t;
  while (t--) {
    cin>>n;
    for (int i=1;i<=n;i++) cin >> ar[i];
    if (ar[n-1] > ar[n]) {
      cout << "-1\n";
      continue;
    }
    bool desc = true;
    for (int i=1;i<n;i++) {
      if (ar[i] > ar[i+1]) desc = false;
    }
    if (desc) {
      cout << "0\n";
      continue;
    }
    if (ar[n-1] - ar[n] > ar[n-1]) {
      cout << "-1\n";
      continue;
    }
    vector<op> res;
    int dif = ar[n-1] - ar[n]; 
    for (int i=1;i<n-1;i++) {
      if (ar[i] != dif) {
        ar[i] = dif;
        res.push_back({i, n-1, n});
      }
    }
    cout << res.size() << '\n';
    for (op r : res) {
      cout << r.x << ' ' << r.y << ' ' << r.z << '\n';
    }
  }
}