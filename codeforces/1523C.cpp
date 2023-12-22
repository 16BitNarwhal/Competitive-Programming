#include <bits/stdc++.h>
using namespace std;
int n, a[1001]; 
int main() { 
  int t;cin>>t;
  while(t--) { 
    cin >> n;
    vector<int> res;
    for (int i=0;i<n;i++)
      cin >> a[i]; 
    for (int i=0;i<n;i++) {
      if (a[i]>1) { 
        while (!res.empty() && res.back()+1 != a[i]) {
          res.pop_back();
        }
        assert(!res.empty());
        res.pop_back();
      }
      res.push_back(a[i]);
      for (int i=0;i<res.size()-1;i++) 
        cout << res[i] << '.';
      cout << res.back() << '\n';
    }
  }
}