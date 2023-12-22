#include <bits/stdc++.h>
using namespace std;
int ar[2002];
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    n *= 2;
    for (int i=0;i<n;i++)
      cin >> ar[i];
    sort(ar, ar+n);
    multiset<int> s;
    bool ans=0;
    for (int i=0;i<n-1;i++) {
      s.clear();
      for (int j=0;j<n;j++) 
        s.insert(ar[j]);
      int x = ar[i] + ar[n-1];
      bool flag=1;
      vector<pair<int,int>> res;
      while (!s.empty()) {
        int mx = *s.rbegin();
        s.erase(s.find(mx));
        if (s.count(x - mx)) {
          s.erase(s.find(x - mx));
          res.push_back({x - mx, mx});
          x = mx;
        } else {
          flag=0; break;
        }
      }
      if (flag) {
        ans = 1; 
        cout << "YES\n";
        cout << ar[i] + ar[n-1] << "\n";
        for (auto p : res) {
          cout << p.first << ' ' << p.second << '\n';
        }
        break;
      }
    }
    if (!ans) cout << "NO\n";
  }
}